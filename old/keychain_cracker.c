/* CIPHERTEXT is encrypted file encryption key */

unsigned int master[8];
pbkdf2(PASSWORD,  strlen(PASSWORD), SALT, SALTLEN, 1000, master);
DES_cblock key1, key2, key3;
DES_cblock ivec;
DES_key_schedule ks1, ks2, ks3;
memcpy(key1, key, 8);
memcpy(key2, key + 8, 8);
memcpy(key3, key + 16, 8);
DES_set_key((C_Block *) key1, &ks1);
DES_set_key((C_Block *) key2, &ks2);
DES_set_key((C_Block *) key3, &ks3);
memcpy(ivec, IV, 8);
DES_ede3_cbc_encrypt(CIPHERTEXT, out, 48, &ks1, &ks2, &ks3, &ivec,  DES_DECRYPT);

// now check padding
pad = out[47];
if(pad > 8)
   // "Bad padding byte. Wrong Password.
   return -1;
if(pad != 4) 
   // "Bad padding value. Wrong Password.
   return -1;
n = CTLEN - pad;
for(i = n; i < CTLEN; i++)
   if(out[i] != pad)
      // "Bad padding. Wrong Password.
   return -1;

// padding check passed, password found!
printf("Password Found");


