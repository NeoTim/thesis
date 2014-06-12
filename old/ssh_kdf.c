generate_key_bytes(PASSWORD, REQUIRED_SIZE, final_key)
{
    unsigned char digest[16] = {0};
    int keyidx = 0;
    int digest_inited = 0;
    int size = 0;

    while (REQUIRED_SIZE > 0) {
        MD5_CTX ctx;
        MD5_Init(&ctx);
        if (digest_inited)
            MD5_Update(&ctx, digest, 16);
        MD5_Update(&ctx, PASSWORD, strlen(PASSWORD));
        /* use first 8 bytes of salt */
        MD5_Update(&ctx, SALT, 8);
        MD5_Final(digest, &ctx);
        digest_inited = 1;
        if (REQUIRED_SIZE > 16)
            size = 16;
        else 
            size = REQUIRED_SIZE;
        /* copy part of digest to keydata */
        for(i = 0; i < size; i++)
            final_key[keyidx++] = digest[i];
        REQUIRED_SIZE -= size;
    }
}


