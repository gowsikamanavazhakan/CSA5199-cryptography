#include <stdio.h>
#include <string.h>
#include <ctype.h>
int isCoprime(int a, int b) {
 while (b != 0) {
 int temp = b;
 b = a % b;
 a = temp;
 }
 return a == 1;
}
int modInverse(int a, int m) {
int x;
 for ( x = 1; x < m; x++) {
 if ((a * x) % m == 1) {
 return x;
 }
 }
 return -1; // Inverse doesn't exist
}
char affineEncrypt(char p, int a, int b) {
 if (isalpha(p)) {
 int base = islower(p) ? 'a' : 'A';
 return ((a * (p - base) + b) % 26) + base;
 }
 return p;
}
char affineDecrypt(char c, int a, int b) {
 if (isalpha(c)) {
 int base = islower(c) ? 'a' : 'A';
 int aInverse = modInverse(a, 26);
 if (aInverse == -1) {
 // Inverse doesn't exist
 return c;
 }
 return ((aInverse * (c - base - b + 26)) % 26) + base;
 }
 return c;
}
int main() {
 int a, b;
 char plaintext[1000];
 char ciphertext[1000];
 
 printf("Enter the plaintext: ");
 fgets(plaintext, sizeof(plaintext), stdin);
 
 printf("Enter the value of 'a' (must be coprime to 26): ");
 scanf("%d", &a);
 
 if (!isCoprime(a, 26)) {
 printf("'a' is not coprime to 26. Encryption is not possible.\n");
 return 1;
 }
 printf("Enter the value of 'b': ");
 scanf("%d", &b);
int i;
 for ( i = 0; i < strlen(plaintext); i++) {
 ciphertext[i] = affineEncrypt(plaintext[i], a, b);
 }
 printf("Encrypted Text: %s\n", ciphertext);
 printf("Decrypting...\n");
 char decryptedText[1000];
 for ( i = 0; i < strlen(ciphertext); i++) {
 decryptedText[i] = affineDecrypt(ciphertext[i], a, b);
 }
 printf("Decrypted Text: %s\n", decryptedText);
 return 0;
}
