/* Derives AES-256 decryption key from USERNAME and PASSWORD */


PKCS5_PBKDF2_HMAC(PASSWORD, strlen(PASSWORD), USERNAME, strlen(USERNAME), ITERATIONS, EVP_sha256(), 32, key);

/* Try decrypting encrypted_username */
AES_KEY akey;
unsigned char iv[16] = { 0 };
AES_set_decrypt_key(key, 256, &akey)
AES_cbc_encrypt(encrypted_username, decrypted_username, 32, &akey, iv, AES_DECRYPT);

if(strcmp(decrypted_username, username) == 0))
    /* Password Found */
else 
   /* Password is not correct */
