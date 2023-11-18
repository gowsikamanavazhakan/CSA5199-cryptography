#include <stdio.h>
#include <string.h>
#include <ctype.h>

void generate_cipher_sequence(char *keyword, char *cipher_sequence) {
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int keyword_length = strlen(keyword);
    int i, j = 0;

    // Copy the keyword to the cipher sequence, removing duplicate characters
    for (i = 0; i < keyword_length; i++) {
        char current_char = toupper(keyword[i]);
        if (strchr(cipher_sequence, current_char) == NULL) {
            cipher_sequence[j++] = current_char;
        }
    }

    // Fill in the remaining characters from the alphabet
    for (i = 0; i < 26; i++) {
        if (strchr(cipher_sequence, alphabet[i]) == NULL) {
            cipher_sequence[j++] = alphabet[i];
        }
    }
    cipher_sequence[j] = '\0';
}

void monoalphabetic_encrypt(char *plaintext, char *keyword, char *ciphertext) {
    char cipher_sequence[27];
    generate_cipher_sequence(keyword, cipher_sequence);
    int i;

    for (i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            char current_char = toupper(plaintext[i]);
            if (isupper(plaintext[i])) {
                ciphertext[i] = cipher_sequence[current_char - 'A'];
            } else {
                ciphertext[i] = tolower(cipher_sequence[current_char - 'A']);
            }
        } else {
            ciphertext[i] = plaintext[i];
        }
    }

    ciphertext[i] = '\0';
}

void monoalphabetic_decrypt(char *ciphertext, char *keyword, char *plaintext) {
    char cipher_sequence[27];
    generate_cipher_sequence(keyword, cipher_sequence);
    int i;

    for (i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            char current_char = toupper(ciphertext[i]);
            if (isupper(ciphertext[i])) {
                plaintext[i] = 'A' + (strchr(cipher_sequence, current_char) - cipher_sequence);
            } else {
                plaintext[i] = 'a' + (strchr(cipher_sequence, current_char) - cipher_sequence);
            }
        } else {
            plaintext[i] = ciphertext[i];
        }
    }

    plaintext[i] = '\0';
}

int main() {
    char keyword[] = "CIPHER";
    char plaintext[] = "Hello, World!";
    char ciphertext[100];
    char decrypted_text[100];

    monoalphabetic_encrypt(plaintext, keyword, ciphertext);
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);

    monoalphabetic_decrypt(ciphertext, keyword, decrypted_text);
    printf("Decrypted Text: %s\n", decrypted_text);

    return 0;
}
