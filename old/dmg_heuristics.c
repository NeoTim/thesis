/* a return code of 1 indicates a successful decryption */

int verify_decrytion(data)
{       
   r = memmem(data, data_length, (void*)"koly", 4);
   if(r) {
       unsigned int *u32Version = (unsigned int *)(r + 4);
       if(HTONL(*u32Version) == 4)
           return 1;
   }
   if(memmem(data, data_length, (void*)"EFI PART", 8))
       return 1;
   if(memmem(data, data_length, (void*)"Apple", 5)) {
       return 1;
   if(memmem(data, data_length, (void*)"Press any key to reboot", 23)) 
       return 1;
   return 0; /* incorrect decryption */
}


