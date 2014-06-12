process_private_keyfile(filename, PASSWORD)
{
    BIO *bp;
    EVP_CIPHER_INFO cipher;
    EVP_PKEY pk;
    bp = BIO_new(BIO_s_file());
    BIO_read_filename(bp, filename);
    PEM_read_bio(bp, &nm, &header, &data, &len);

    PEM_do_header(&cipher, data, &len, NULL, PASSWORD);

    if ((dsapkc = d2i_DSAPrivateKey(NULL, &data, len)) != NULL) {
	    /* found PASSWORD */
    }
    else
	    /* wrong PASSWORD */
}

