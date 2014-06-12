S2KSimpleMD5Generator(char *password, unsigned char *key, int length)
{
    MD5_CTX ctx;
    uint32_t numHashes = (length + MD5_DIGEST_LENGTH - 1) / MD5_DIGEST_LENGTH;
    int i, j;

    for (i = 0; i < numHashes; i++) {
        MD5_Init(&ctx);
        for (j = 0; j < i; j++) {
            MD5_Update(&ctx, "\0", 1);
        }
        MD5_Update(&ctx, password, strlen(password));
        MD5_Final(key + (i * MD5_DIGEST_LENGTH), &ctx);
    }
}
