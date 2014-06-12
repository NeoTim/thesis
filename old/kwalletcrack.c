verify_passphrase(passphrase)
{
    unsigned char key[20];
    password2hash(passphrase, key); /* use custom KDF */
    SHA_CTX ctx;
    BlowFish _bf;
    CipherBlockChain bf(&_bf);
    bf.setKey((void *) key, 20 * 8);
    bf.decrypt(CIPHERTEXT, CTLEN);

    // strip the leading data, one block of random data
    t = CIPHERTEXT + 8;

    // strip the file size off
    long fsize = 0;
    fsize |= (long (*t) << 24) &0xff000000;
    t++;
    fsize |= (long (*t) << 16) &0x00ff0000;
    t++;
    fsize |= (long (*t) << 8) &0x0000ff00;
    t++;
    fsize |= long (*t) & 0x000000ff;
    t++;
    if (fsize < 0 || fsize > long (encrypted_size) - 8 - 4) {
        // file structure error. wrong password
        return -1;
    }
    SHA1_Init(&ctx);
    SHA1_Update(&ctx, t, fsize);
    SHA1_Final(testhash, &ctx);
    // compare hashes
    sz = encrypted_size;
    for (i = 0; i < 20; i++) {
        if (testhash[i] != buffer[sz - 20 + i]) {
            return -1; /* wrong password */
        }
    }
    printf("Password Found!");
}


