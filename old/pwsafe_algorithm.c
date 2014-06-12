SHA256_CTX ctx;

SHA256_Init(&ctx);
SHA256_Update(&ctx, password, strlen(password);
SHA256_Update(&ctx, SALT, 32);
SHA256_Final(output, &ctx);

for(int i = 0; i <= ITER; i++)  {
	SHA256_Init(&ctx);
	SHA256_Update(&ctx, output, 32);
	SHA256_Final(output, &ctx);
}

if(output == HASH) {
	/* password cracked */
}
