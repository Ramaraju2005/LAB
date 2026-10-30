
#include <stdio.h>

int main() {
    char s[100];
    int key, i;

    printf("Enter text: ");
    scanf("%s", s);

    printf("Enter key: ");
    scanf("%d", &key);

    for (i = 0; s[i]; i++)
        s[i] = (s[i] - 'A' + key) % 26 + 'A';

    printf("Encrypted: %s\n", s);

    for (i = 0; s[i]; i++)
        s[i] = (s[i] - 'A' - key + 26) % 26 + 'A';

    printf("Decrypted: %s\n", s);

    return 0;
}


// -------sample output:
// Enter text: HELLO
// Enter key: 3
// Encrypted: KHOOR
// Decrypted: HELLO