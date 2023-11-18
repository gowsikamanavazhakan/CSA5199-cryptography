#include <stdio.h> 
 
// Function to find the multiplicative inverse of 'a' modulo 26 
int findMultiplicativeInverse(int a) { 
 int inverse; 
 for (inverse = 1; inverse < 26; inverse++) { 
 if ((a * inverse) % 26 == 1) { 
 return inverse; 
 } 
 } 
 return -1; // Inverse not found 
} 
 
int main() { 
 // Most frequent and second most frequent letters 
 char mostFrequent = 'B'; 
 char secondMostFrequent = 'U'; 
 
 // Convert characters to integers (A=0, B=1, ..., Z=25) 
 int mostFrequentValue = mostFrequent - 'A'; 
 int secondMostFrequentValue = secondMostFrequent - 'A'; 
 
 // Calculate the potential 'a' value 
 int a = (mostFrequentValue - secondMostFrequentValue + 26) % 26; 
 
 // Find the multiplicative inverse of 'a' modulo 26 
 int inverseA = findMultiplicativeInverse(a); 
 
 if (inverseA == -1) { 
 printf("The multiplicative inverse of 'a' does not exist. Cannot break the cipher.\n"); 
 return 1; 
 } 
 
 // Calculate 'b' using the equation E(x) = (ax + b) mod 26 
 int b = (mostFrequentValue - (inverseA * mostFrequentValue)) % 26; 
 if (b < 0) { 
 b += 26; // Ensure b is positive 
 } 
 
 printf("Affine Cipher Parameters:\n"); 
 printf("a = %d\n", a); 
 printf("b = %d\n", b); 
 printf("Inverse of a = %d\n", inverseA); 
 printf("Plaintext:\n"); 
 
 // Decrypt the ciphertext using the found 'a' and 'b' values 
 char ciphertext[] = "YOUR_CIPHERTEXT_HERE"; 
 int ciphertextLength = strlen(ciphertext); 
 int i ; 
 for ( i = 0; i < ciphertextLength; i++) { 
 char encryptedChar = ciphertext[i]; 
 if (encryptedChar >= 'A' && encryptedChar <= 'Z') { 
 int encryptedValue = encryptedChar - 'A'; 
 int decryptedValue = (inverseA * (encryptedValue - b)) % 26; 
 if (decryptedValue < 0) { 
 decryptedValue += 26; // Ensure it's positive 
 } 
 char decryptedChar = decryptedValue + 'A'; 
 printf("%c", decryptedChar); 
 } else { 
 printf("%c", encryptedChar); // Keep non-alphabetic characters unchanged 
 } 
 } 
 printf("\n"); 
 
 return 0; 
}
