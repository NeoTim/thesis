S2KItSaltedSHA1Generator(char *password, unsigned char *key, int length)
{
    unsigned char keybuf[KEYBUFFER_LENGTH];
    SHA_CTX ctx;
    int i, j;
    int32_t tl;
    int32_t mul;
    int32_t bs;
    uint8_t *bptr;
    int32_t n;

    uint32_t numHashes = (length + SHA_DIGEST_LENGTH - 1) / SHA_DIGEST_LENGTH;
    memcpy(keybuf, cur_salt->salt, 8);

    for (i = 0; i < numHashes; i++) {
        SHA1_Init(&ctx);
        for (j = 0; j < i; j++) {
            SHA1_Update(&ctx, "\0", 1);
        }
        // Find multiplicator
        tl = strlen(password) + 8;
        mul = 1;
        while (mul < tl && ((64 * mul) % tl)) {
            ++mul;
        }
        // Try to feed the hash function with 64-byte blocks
        bs = mul * 64;
        bptr = keybuf + tl;
        n = bs / tl;
        memcpy(keybuf + 8, password, strlen(password));
        while (n-- > 1) {
            memcpy(bptr, keybuf, tl);
            bptr += tl;
        }
        n = cur_salt->count / bs;
        while (n-- > 0) {
            SHA1_Update(&ctx, keybuf, bs);
        }
        SHA1_Update(&ctx, keybuf, cur_salt->count % bs);
        SHA1_Final(key + (i * SHA_DIGEST_LENGTH), &ctx);
    }
}


