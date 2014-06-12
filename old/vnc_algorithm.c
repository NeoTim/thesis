unsigned char OUT[16] = { 0 };

/* key processing */
for(i = 0; i < strlen((const char*)key); i++)
	PASSWORD[i] = BIT_FLIP(PASSWORD[i]);

/* encrypt challenge using PASSWORD */
memcpy(des_key, PASSWORD, 8);
DES_set_odd_parity(&des_key);
DES_set_key_checked(&des_key, &schedule);
DES_cbc_encrypt(CHALLENGE[0:8], &OUT[0], 8,
		&schedule, &ivec, DES_ENCRYPT);
DES_cbc_encrypt(CHALLENGE[8:16], &OUT[8], 8,
		&schedule, &ivec, DES_ENCRYPT);

if(OUT == RESPONSE) {
	/* password found */
}
