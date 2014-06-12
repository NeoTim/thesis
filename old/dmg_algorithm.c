AES_KEY aes_decrypt_key;
       
/* derive dervied_key from user password, this is used in un-wrapping operation */
pbkdf2(UserPassword, strlen(UserPassword), salt, 20, 1000, derived_key);

/* decrypt encrypted_keyblob (the wrapped key), un-wrap operation */
DES_ede3_cbc_encrypt(encrypted_keyblob, decrypted_key, DES_key_schedule values..., IV, DES_DECRYPT);

/* un-wrapped key (decrypted_key) is used now for data decryption 
 * Derive IV to be used in AES decryption based on chunk number to be decrypted */

memcpy(aes_key, decrypted_key, 32);
memcpy(hmacsha1_key, decrypted_key, 20);
HMAC_CTX_init(&ctx);
HMAC_Init_ex(&ctx, hmacsha1_key, 20, EVP_sha1(), NULL);
HMAC_Update(&ctx, ChunkNumber, 4);
HMAC_Final(&ctx, iv);

/* Decrypt chunk using derived iv and derived AES key */
AES_set_decrypt_key(aes_key, 128, &aes_decrypt_key);
AES_cbc_encrypt(chunk, data, data_size, &aes_decrypt_key, iv, AES_DECRYPT);

/* data now contains decrypted data */

