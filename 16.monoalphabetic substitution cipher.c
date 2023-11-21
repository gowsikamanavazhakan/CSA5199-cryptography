#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define ALPHABET_SIZE 26
#define NUM_TOP_PLAINTEXTS 10
const double englishLetterFreq[ALPHABET_SIZE] = {
 0.0817, 0.0149, 0.0278, 0.0425, 0.1270, 0.0223, 0.0202, 0.0609,
 0.0697, 0.0015, 0.0077, 0.0403, 0.0241, 0.0675, 0.0751, 0.0193,
 0.0010, 0.0599, 0.0633, 0.0906, 0.0276, 0.0098, 0.0236, 0.0015,
 0.0197, 0.0007
};
void calculateLetterFrequency(const char *text, double *freq) {
 int totalLetters = 0,i;

 for (i = 0; text[i]; i++) {
 if (isalpha(text[i])) {
 freq[tolower(text[i]) - 'a']++;
 totalLetters++;
 }
 }
 for (i = 0; i < ALPHABET_SIZE; i++) {
 freq[i] /= totalLetters;
 }
}
double calculateScore(const double *freq) {
 double score = 0.0;
 int i;
 for ( i = 0; i < ALPHABET_SIZE; i++) {
 score += freq[i] * englishLetterFreq[i];
 }
 return score;
}
void decryptSubstitution(const char *ciphertext, char *plaintext, int shift) {
int i;
 for (i = 0; ciphertext[i]; i++) {
 if (isalpha(ciphertext[i])) {
 char base = isupper(ciphertext[i]) ? 'A' : 'a';
 plaintext[i] = (ciphertext[i] - base - shift + ALPHABET_SIZE) % ALPHABET_SIZE + base;
 } else {
 plaintext[i] = ciphertext[i];
 }
 }
 plaintext[strlen(ciphertext)] = '\0';
}
int main() {
 const char *ciphertext = "FALSXY XS LSX!"; // Replace with your ciphertext
 double ciphertextFreq[ALPHABET_SIZE] = {0.0};
 int shift;
 calculateLetterFrequency(ciphertext, ciphertextFreq);
 printf("Ciphertext: %s\n\n", ciphertext);
 printf("Top %d possible plaintexts:\n", NUM_TOP_PLAINTEXTS);
 for (shift = 0; shift < ALPHABET_SIZE; shift++) {
 char possiblePlaintext[strlen(ciphertext) + 1];
 decryptSubstitution(ciphertext, possiblePlaintext, shift);
 double possiblePlaintextFreq[ALPHABET_SIZE] = {0.0};
 calculateLetterFrequency(possiblePlaintext, possiblePlaintextFreq);
 double score = calculateScore(possiblePlaintextFreq);
 printf("Shift %d: %s (Score: %.4f)\n", shift, possiblePlaintext, score);
 }
 return 0;
}

OUTPUT:
Ciphertext: FALSXY XS LSX!

Top 10 possible plaintexts:
Shift 0: FALSXY XS LSX! (Score: 0.0362)
Shift 1: EZKRWX WR KRW! (Score: 0.0359)
Shift 2: DYJQVW VQ JQV! (Score: 0.0110)
Shift 3: CXIPUV UP IPU! (Score: 0.0290)
Shift 4: BWHOTU TO HOT! (Score: 0.0623)
Shift 5: AVGNST SN GNS! (Score: 0.0559)
Shift 6: ZUFMRS RM FMR! (Score: 0.0353)
Shift 7: YTELQR QL ELQ! (Score: 0.0498)
Shift 8: XSDKPQ PK DKP! (Score: 0.0211)
Shift 9: WRCJOP OJ CJO! (Score: 0.0353)
Shift 10: VQBINO NI BIN! (Score: 0.0479)
