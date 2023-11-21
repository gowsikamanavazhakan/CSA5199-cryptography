#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define ALPHABETSIZE 26

// Function to calculate the frequency of each letter in the input text
void calculateLetterFrequency(const char *text, int *frequency) {
	int i;
    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char letter = tolower(text[i]);
            frequency[letter - 'a']++;
        }
    }
}

// Function to score the plaintext based on letter frequency
int scorePlaintext(const char *text, const int *expectedFrequency) {
	int i;
    int frequency[ALPHABETSIZE] = {0};
    calculateLetterFrequency(text, frequency);

    int score = 0;
    for (i = 0; i < ALPHABETSIZE; i++) {
        score += abs(frequency[i] - expectedFrequency[i]);
    }

    return score;
}

// Function to decrypt the ciphertext with a given shift
void decryptWithShift(const char *ciphertext, int shift, char *plaintext) {
	int i;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            char base = islower(ciphertext[i]) ? 'a' : 'A';
            plaintext[i] = (ciphertext[i] - shift - base + ALPHABETSIZE) % ALPHABETSIZE + base;
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
}

int main() {
    char ciphertext[1000];
    printf("Enter the ciphertext: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);

    int expectedFrequency[ALPHABETSIZE] = {
        8, 1, 3, 4, 13, 2, 2, 6, 7, 0, 1, 4, 2, 7, 8, 2, 0, 6, 6, 9, 3, 1, 0, 2, 0, 1
    };

    int numTopPlaintexts;
    printf("Enter the number of top possible plaintexts to display: ");
    scanf("%d", &numTopPlaintexts);
    getchar(); // Consume the newline character

    int minScore[numTopPlaintexts];
    char topPlaintexts[numTopPlaintexts][1000];
	int shift;
    for ( shift = 0; shift < ALPHABETSIZE; shift++) {
        char plaintext[1000];
        decryptWithShift(ciphertext, shift, plaintext);

        int score = scorePlaintext(plaintext, expectedFrequency);
		int i,j;
        for ( i = 0; i < numTopPlaintexts; i++) {
            if (score < minScore[i] || i == 0) {
                for (j = numTopPlaintexts - 1; j > i; j--) {
                    minScore[j] = minScore[j - 1];
                    strcpy(topPlaintexts[j], topPlaintexts[j - 1]);
                }
                minScore[i] = score;
                strcpy(topPlaintexts[i], plaintext);
                break;
            }
        }
    }

    printf("\nTop %d possible plaintexts in rough order of likelihood:\n", numTopPlaintexts);
    int i;
    for (i = 0; i < numTopPlaintexts; i++) {
        printf("%d. Score: %d, Plaintext: %s", i + 1, minScore[i], topPlaintexts[i]);
    }

    return 0;
}

OUTPUT:
Enter the ciphertext: saravanan
Enter the number of top possible plaintexts to display: 3
Top 3 possible plaintexts in rough order of likelihood:
1. Score: 97, Plaintext: tbsbwbobo
2. Score: 91, Plaintext: uctcxcpcp
3. Score: 95, Plaintext: vdudydqdq
