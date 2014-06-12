int check_padding_and_structure(out, length)
{
    pad = out[length - 1];
    if(pad > 16) return -1; // Bad padding byte
    n = length - pad;
    for(i = n; i < length; i++) // check padding
        if(out[i] != pad) return -1;

    /* match structure with known standard structure */
    outfile = BIO_new(BIO_s_mem());
    ASN1_parse(outfile, out, legnth, 0);
    BIO_gets(outfile, (char*)output, N);
    res = memem(output, 128, "SEQUENCE", 8);
    if (!res) goto bad;
    BIO_gets(outfile, (char*)output, N);
    res = memem(output, 128, ":00", 3);
    if (!res) goto bad;
    res = memem(output, 128, "INTEGER", 7);
    if (!res) goto bad;
    BIO_gets(outfile, (char*)output, N);
    res = memem(output, 128, "INTEGER", 7);
    if (!res) goto bad;
    /* now this integer has to be big, check minimum length */
    ul = strlen((char*)res);
    p = res;
    while(*p) {
        if (isspace(*p))
            ul--;
        p++;
    }
    if (ul < 32) goto bad;
    return 0;
bad:
    return -1;
}

generate_key_bytes(PASSWORD, 16, key);
AES_set_decrypt_key(key, 128, &akey);
memcpy(iv, SALT, 16);

// We don't decrypt all the encrypted key material!
AES_cbc_encrypt(CIPHERTEXT, PLAINTEXT, 32, &akey, iv, AES_DECRYPT);

// 2 blocks (32 bytes) are enough to self-recover from bad IV, required for correct padding check
AES_cbc_encrypt(CIPHERTEXT + LENGTH - 32, PLAINTEXT + LENGTH - 32, 32, &akey, iv, AES_DECRYPT);

if (check_padding_and_structure(PLAINTEXT, LENGTH) == 0)
    /* Password Found */
else
    /* Password was not correct */

