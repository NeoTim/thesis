/* CIPHERTEXT is encrypted random key */

#define CTLEN 1040

unsigned int master[8];
pbkdf2(PASSWORD, strlen(PASSWORD), SALT, SALTLEN, iterations, master);
AES_KEY akey;
AES_set_decrypt_key(master, 128, &akey);
AES_cbc_encrypt(CIPHERTEXT, out, CTLEN, &akey, iv, AES_DECRYPT);

// now check padding
pad = out[CTLEN - 1];
if(pad < 1 || pad > 16) /* AES block size is 128 bits = 16 bytes */
   // "Bad padding byte. You probably have a wrong password"
   return -1;

n = CTLEN - pad;
key_size = n / 8;

if(key_size != 128 && key_size != 192 && key_size != 256)
   // "invalid key size"
   return -1;
for(i = n; i < CTLEN; i++)
   if(out[i] != pad)
      // "Bad padding. You probably have a wrong password"
      return -1;

// padding check passed, password found!
printf("Password Found");


