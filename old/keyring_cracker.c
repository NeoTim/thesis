decrypt_buffer(buffer, len, salt, iterations, password)
{
	unsigned char key[32];
	unsigned char iv[32];
	AES_KEY akey;
	symkey_generate_simple(password, strlen(password), salt, 8, iterations, key, iv);

	(AES_set_decrypt_key(key, 128, &akey);
	AES_cbc_encrypt(buffer, buffer, len, &akey, iv, AES_DECRYPT);
}

verify_decrypted_buffer(buffer, len)
{
	unsigned char digest[16];
	MD5_CTX ctx;
	MD5_Init(&ctx);
	MD5_Update(&ctx, buffer + 16, len - 16);
	MD5_Final(digest, &ctx);
	return memcmp(buffer, digest, 16) == 0;
}

decrypt_buffer(input, crypto_size, salt, iterations, password);
if (verify_decrypted_buffer(input, cur_salt->crypto_size) == 1)
	/* Password found */
else
	/* Password is incorrect */
