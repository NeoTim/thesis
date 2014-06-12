password2key(PASSWORD)
{
    int passlen = strlen(PASSWORD);
    unsigned char key[40];
    SHA_CTX s;
    SHA1_Init(&s);
    SHA1_Update(&s, (void*)"\0\0\0\0", 4);
    SHA1_Update(&s, passphrase, passlen);
    SHA1_Final(key + 0, &s);
    SHA1_Init(&s);
    SHA1_Update(&s, (void*)"\0\0\0\1", 4);
    SHA1_Update(&s, passphrase, passlen);
    SHA1_Final(key + 20, &s);
    
    /* variable key now contains AES-256 key */
    
}


