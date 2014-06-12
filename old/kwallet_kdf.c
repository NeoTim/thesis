password2hash(password, output)
{
    SHA_CTX ctx;
    unsigned char block1[20] = { 0 };
    int i;

    SHA1_Init(&ctx);
    SHA1_Update(&ctx, password, MIN(strlen(password), 16));
    for (i = 0; i < 2000; i++) {
        SHA1_Final(block1, &ctx);
        SHA1_Init(&ctx);
        SHA1_Update(&ctx, block1, 20);
    }
    memcpy(hash, block1, 20);
}
