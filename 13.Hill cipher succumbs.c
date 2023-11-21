#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int encrypt(char plaintext, char key) {
    if (isalpha(plaintext)) {
        int shift;
        if (islower(plaintext)) {
            shift = key - 'a';
            return (plaintext - 'a' + shift) % 26 + 'a';
        } else if (isupper(plaintext)) {
            shift = key - 'A';
            return (plaintext - 'A' + shift) % 26 + 'A';
        }
    }
    return plaintext;  // Non-alphabetic characters remain unchanged
}

int main() {
    char plaintext[1000];
    char key[1000];
    char ciphertext[1000];
    int key_length;

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter the key as a stream of numbers (0-26) separated by spaces: ");
    fgets(key, sizeof(key), stdin);

    key_length = 0;
    char *token = strtok(key, " ");
    while (token != NULL) {
        int shift = atoi(token);
        key_length++;
        token = strtok(NULL, " ");
        ciphertext[key_length - 1] = shift;
    }
	int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        ciphertext[i] = encrypt(plaintext[i], ciphertext[i % key_length]);
    }

    printf("Encrypted text: %s\n", ciphertext);

    for (i = 0; plaintext[i] != '\0'; i++) {
        plaintext[i] = encrypt(ciphertext[i], ciphertext[i % key_length]);
    }

    printf("Decrypted text: %s\n", plaintext);

    return 0;
}

OUTPUT:
Enter the plaintext: goodevening
Enter the key as a stream of numbers (0-26) separated by spaces: 14
Encrypted text: HVVKL]LUPUN

Decrypted text: OCCRS]SBWBU
