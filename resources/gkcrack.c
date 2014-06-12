#include <gnome-keyring.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	char passphrase[128];
	GnomeKeyringResult r;

	/* argv[1] contains target keychain's name */
	while(fgets(passphrase, N, stdin) != NULL) {
		r = gnome_keyring_unlock_sync(argv[1], passphrase);
		if (r == GNOME_KEYRING_RESULT_OK) {
			printf("Password Found : %s\n", passphrase);
			exit(0);
		}
	}
	return 0;
}
