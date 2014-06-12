/* custom KDF based on AES and SHA256 */

transform_key(char *PASSWORD, final_key)
{
     // First, hash the PASSWORD
    SHA256_CTX ctx;
    AES_KEY akey;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, PASSWORD, strlen(PASSWORD));
    SHA256_Final(hash, &ctx);
    if(version == 2) { /* 2.x database */
        SHA256_Init(&ctx);
        SHA256_Update(&ctx, hash, 32);
        SHA256_Final(hash, &ctx);
    }
    AES_set_encrypt_key(TRS, 256, &akey);    
    // Next, encrypt the created hash
    for(i = 0; i < ITERATIONSl; i++) {
        AES_encrypt(hash, hash, &akey);
        AES_encrypt(hash+16, hash+16, &akey);
    }
    // Finally, hash it again...
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, hash, 32);
    SHA256_Final(hash, &ctx);
    // and hash the result together with the Final Random Seed
    SHA256_Init(&ctx);
    if(version == 1) {
        SHA256_Update(&ctx, FRS, 16);
    }
    else {
        SHA256_Update(&ctx, FRS, 32);
    }
    SHA256_Update(&ctx, hash, 32);
    SHA256_Final(final_key, &ctx);
}

