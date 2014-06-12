try_key(unsigned char *key)
{
    unsigned char output[32];
    RC4_KEY arc4;
    RC4_set_key(&arc4, 5, key);
    /* encrypt padding */
    RC4(&arc4, 32, padding, output);

    /* compare padding to original value of u */
    if(memcmp(output, u, 32) == 0) {
        puts("Found RC4 40-bit key!")
        exit(0);
    }
}

keyspace_search()
{
    int i, j, k;
    int is = 0x00;
    int js = 0x00;
    int ks = 0x00;
    int ls = 0x00;
    int ms = 0x00;

    for(i = is; i <= 255; i++) {
        for(j = js; j <= 255; j++) {
#pragma omp parallel for
            for(k = ks; k <= 255; k++) {
                int l, m;
                for(l = ls; l <= 255; l++) {
                    for(m = ms; m <= 255; m++) {
                        unsigned char hashBuf[5];
                        hashBuf[0] = (char)i;
                        hashBuf[1] = (char)j;
                        hashBuf[2] = (char)k;
                        hashBuf[3] = (char)l;
                        hashBuf[4] = (char)m;
                        try_key(hashBuf);
                    }
                }
            }
        }
    }
}
