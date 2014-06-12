/* derive decryption key from PASSWORD and SALT using custom KDF */

S2KItSaltedSHA1Generator(char *password, unsigned char *key, int length);

S2KItSaltedSHA1Generator(PASSWORD, keydata, KEY_SIZE);

/* decrypt encrypted key material */

// Decrypt first data block in order to check the first two bits of
// the MPI. If they are correct, there's a good chance that the
// password is correct, too.

unsigned char ivec[32];
unsigned char out[4096];
int tmp = 0;
uint32_t num_bits;
int checksumOk;
int i;

// Quick Hack
memcpy(ivec, cur_salt->iv, blockSize(cur_salt->cipher_algorithm));
CAST_KEY ck;
CAST_set_key(&ck, ks, keydata);
CAST_cfb64_encrypt(cur_salt->data, out, CAST_BLOCK, &ck, ivec, &tmp, CAST_DECRYPT);

num_bits = ((out[0] << 8) | out[1]);
if (num_bits < MIN_BN_BITS || num_bits > cur_salt->bits) {
   return 0;
}

// Decrypt all data
memcpy(ivec, cur_salt->iv, blockSize(cur_salt->cipher_algorithm));
tmp = 0;
CAST_KEY ck;
CAST_set_key(&ck, ks, keydata);
CAST_cfb64_encrypt(cur_salt->data, out, cur_salt->datalen, &ck, ivec, &tmp, CAST_DECRYPT);

// Verify
checksumOk = 0;
uint8_t checksum[SHA_DIGEST_LENGTH];
SHA_CTX ctx;
SHA1_Init(&ctx);
SHA1_Update(&ctx, out, cur_salt->datalen - SHA_DIGEST_LENGTH);
SHA1_Final(checksum, &ctx);
if (memcmp(checksum, out + cur_salt->datalen - SHA_DIGEST_LENGTH, SHA_DIGEST_LENGTH) == 0) {
   checksumOk = 1;
}

// If the checksum is ok, try to parse the first MPI of the private key
if (checksumOk) {
   BIGNUM *b = NULL;
   uint32_t blen = (num_bits + 7) / 8;
   if (blen < cur_salt->datalen && ((b = BN_bin2bn(out + 2, blen, NULL)) != NULL)) {
      BN_free(b);
      return 1;
   }
}

return 0;

if(res)
   any_cracked = cracked[index] = 1;




