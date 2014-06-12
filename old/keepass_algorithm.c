transform_key(PASSWORD, final_key); /* use custom KDF */

AES_set_decrypt_key(final_key, 256, &akey);
if(VERSION == 1) {
	AES_cbc_encrypt(CIPHERTEXT, PLAINTEXT, SIZE, &akey, IV, AES_DECRYPT);
	pad_byte = PLAINTEXT[SIZE-1];
	datasize = cur_salt->contentsize - pad_byte;
	SHA256_Init(&ctx);
	SHA256_Update(&ctx, PLAINTEXT, datasize);
	SHA256_Final(out, &ctx);
	if(out == CHASH) {
		/* password found */
	}
}
else {
	AES_cbc_encrypt(CIPHERTEXT, PLAINTEXT, 32, &akey, iv, AES_DECRYPT);
	if(memcmp(PLAINTEXT, expected_bytes, 32) == 0)
		/* password found */
}
