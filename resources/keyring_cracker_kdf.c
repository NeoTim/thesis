/* derive KEY and IV from PASSWORD and SALT */

symkey_generate_simple(PASSWORD, SALT, iterations, key, iv)
{
   at_key = key;
   at_iv = iv;
   needed_key = 16;
   needed_iv = 16;
   n_digest = 32;  /* SHA256 digest size */

   for (pass = 0;; ++pass) {
      SHA256_Init(&ctx);      
      /* Hash in the previous buffer on later passes */
      if (pass > 0)
         SHA256_Update(&ctx, digest, n_digest);

      if (password) {
         SHA256_Update(&ctx, password, n_password);

      if (salt && n_salt)
         SHA256_Update(&ctx, salt, n_salt);

     SHA256_Final(digest, &ctx);

     for (i = 1; i < iterations; ++i) {
        SHA256_Init(&ctx);
        SHA256_Update(&ctx, digest, n_digest);
        SHA256_Final(digest, &ctx);
     }
     /* Copy as much as possible into the destinations */
     i = 0;
     while (needed_key && i < n_digest) {
        *(at_key++) = digest[i];
        needed_key--;
        i++;
     }
     while (needed_iv && i < n_digest) {
        if (at_iv)
            *(at_iv++) = digest[i];
            needed_iv--;
            i++;
     }
     if (needed_key == 0 && needed_iv == 0)
        break;
   }
}

