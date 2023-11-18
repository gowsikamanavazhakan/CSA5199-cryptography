#include <stdio.h>
#include <string.h>
void polySubstitution(char *plaintext, char *key) {
 int plainLen = strlen(plaintext);
 int keyLen = strlen(key);
 for (int i = 0; i < plainLen; i++) {
 // Calculate the offset for the current character in the key
 int keyOffset = key[i % keyLen] - 'A';
 // Check if the character is a letter
 if (isalpha(plaintext[i])) {
 char base = islower(plaintext[i]) ? 'a' : 'A';
 char shiftedChar = (plaintext[i] - base + keyOffset) % 26 + base;
 printf("%c", shiftedChar);
 } else {
 // Non-letter characters are left unchanged
 printf("%c", plaintext[i]);
 }
 }
}
int main() {
 char plaintext[100];
 char key[100];
 printf("Enter the plaintext: ");
 fgets(plaintext, sizeof(plaintext), stdin);
 plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove newline character
 printf("Enter the key: ");
 fgets(key, sizeof(key), stdin);
 key[strcspn(key, "\n")] = '\0'; // Remove newline character
 printf("Encrypted text: ");
 polySubstitution(plaintext, key);
 printf("\n");
 return 0;
}

OUTPUT:
Enter the plaintext: examination
Enter the key: the
Encrypted text: dkklvxzgsna
