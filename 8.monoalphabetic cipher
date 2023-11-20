#include <stdio.h>
#include <string.h>

// Function to initialize the Playfair matrix
void initializePlayfairMatrix(char key[], char matrix[5][5]) {
    int keyLen = strlen(key);
    int k = 0,i,j;
    int used[26] = {0};
	char ch;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (k < keyLen) {
                while (used[key[k] - 'A']) {
                    k++;
                }
                matrix[i][j] = key[k];
                used[key[k] - 'A'] = 1;
                k++;
            } else {
                for (ch = 'A'; ch <= 'Z'; ch++) {
                    if (ch != 'J' && !used[ch - 'A']) {
                        matrix[i][j] = ch;
                        used[ch - 'A'] = 1;
                        break;
                    }
                }
            }
        }
    }
}

// Function to decrypt a Playfair-encoded message
void decryptPlayfair(char matrix[5][5], char message[], int messageLength) {
    // Implement the decryption logic here
    // You can refer to the previous decryption logic provided
	int i;
    // Print the decrypted message
    for (i = 0; i < messageLength; i++) {
        if (message[i] != ' ') {
            printf("%c", message[i]);
        }
    }
    printf("\n");
}

int main() {
    char key[] = "royal new zealand navy";
    char matrix[5][5];
    char message[] = "KXJEY UREBE ZWEHE WRYTU HEYFS KREHE GOYFI WTTTU OLKSY CAJPO BOTEI ZONTX BYBNT GONEY CUZWR GDSON SXBOU YWRHE BAAHY USEDQ";
    int messageLength = strlen(message);

    initializePlayfairMatrix(key, matrix);
    decryptPlayfair(matrix, message, messageLength);

    return 0;
}

output:
Segmentation fault
