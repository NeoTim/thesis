unsigned char iv[32] = { 0 };
(AES_set_decrypt_key(key, 256, &akey);
AES_cbc_encrypt(private_blob, out , private_blob_length, &akey, iv, AES_DECRYPT);

/* Verify the MAC. */
char realmac[41];
unsigned char binary[20];
unsigned char *macdata;
int maclen;
int free_macdata;
int i;
unsigned char *p;
int namelen = strlen(cur_salt->alg);
int enclen = strlen(cur_salt->encryption);
int commlen = strlen(cur_salt->comment);
maclen = (4 + namelen +
		4 + enclen +
		4 + commlen +
		4 + cur_salt->public_blob_len +
		4 + cur_salt->private_blob_len);
macdata = (unsigned char*)malloc(maclen);
p = macdata;
#define DO_STR(s,len) PUT_32BIT(p,(len));memcpy(p+4,(s),(len));p+=4+(len)
DO_STR(cur_salt->alg, namelen);
DO_STR(cur_salt->encryption, enclen);
DO_STR(cur_salt->comment, commlen);
DO_STR(cur_salt->public_blob, cur_salt->public_blob_len);
DO_STR(out, cur_salt->private_blob_len);
free_macdata = 1;
}
if (cur_salt->is_mac) {
	SHA_CTX s;
	unsigned char mackey[20];
	unsigned int length = 20;
	// HMAC_CTX ctx;
	char header[] = "putty-private-key-file-mac-key";
	SHA1_Init(&s);
	SHA1_Update(&s, header, sizeof(header)-1);
	if (cur_salt->cipher && passphrase)
		SHA_Update(&s, passphrase, passlen);
	SHA1_Final(mackey, &s);
	hmac_sha1(mackey, 20, macdata, maclen, binary, length);
	/* HMAC_Init(&ctx, mackey, 20, EVP_sha1());
	 * HMAC_Update(&ctx, macdata, maclen);
	 * HMAC_Final(&ctx, binary, &length);
	 * HMAC_CTX_cleanup(&ctx); */
} else {
	SHA_Simple(macdata, maclen, binary);
}
if (free_macdata)
	MEM_FREE(macdata);
for (i = 0; i < 20; i++)
	sprintf(realmac + 2 * i, "%02x", binary[i]);

if (strcmp(cur_salt->mac, realmac) == 0)
	return 1; /* Password Found */

error:
return 0; /* Wrong Password */
}
