#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Size of the Playfair matrix
#define SIZE 5

// Function to create the Playfair matrix from the given key
void createPlayfairMatrix(char key[], char matrix[SIZE][SIZE]) {
    int i, j;
    int k = 0;
    int keyLen = strlen(key);
    char usedChars[26] = {0}; // To keep track of used characters

    // Initialize the matrix with zeros
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            matrix[i][j] = ' ';
        }
    }

    // Fill the matrix with the key
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (k < keyLen) {
                char c = toupper(key[k]);
                // Replace 'J' with 'I' in the key
                if (c == 'J') c = 'I';

                // Check if the character is not already used
                if (usedChars[c - 'A'] == 0) {
                    matrix[i][j] = c;
                    usedChars[c - 'A'] = 1;
                    k++;
                }
            }
        }
    }

    // Fill the remaining matrix with the alphabet
    char currentChar = 'A';
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (matrix[i][j] == ' ') {
                while (usedChars[currentChar - 'A'] != 0) {
                    currentChar++;
                }
                matrix[i][j] = currentChar;
                usedChars[currentChar - 'A'] = 1;
            }
        }
    }
}

// Function to find the position of a character in the Playfair matrix
void findPosition(char matrix[SIZE][SIZE], char c, int *row, int *col) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (matrix[i][j] == c) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// Function to encrypt a message using the Playfair cipher
void playfairEncrypt(char matrix[SIZE][SIZE], char message[]) {
    int len = strlen(message);
    int i,j;

    // Remove any spaces from the message
    for (i = 0; i < len; i++) {
        if (message[i] == ' ') {
            for (j = i; j < len; j++) {
                message[j] = message[j + 1];
            }
            len--;
        }
    }

    // If the message length is odd, append 'X' to it
    if (len % 2 != 0) {
        message[len] = 'X';
        len++;
    }

    // Iterate over the message and encrypt it
    for (i = 0; i < len; i += 2) {
        int row1, col1, row2, col2;
        char a = toupper(message[i]);
        char b = toupper(message[i + 1]);

        findPosition(matrix, a, &row1, &col1);
        findPosition(matrix, b, &row2, &col2);

        // If the letters are in the same row, shift them to the right
        if (row1 == row2) {
            col1 = (col1 + 1) % SIZE;
            col2 = (col2 + 1) % SIZE;
        }
        // If the letters are in the same column, shift them down
        else if (col1 == col2) {
            row1 = (row1 + 1) % SIZE;
            row2 = (row2 + 1) % SIZE;
        }
        // Otherwise, form a rectangle and swap the columns
        else {
            int temp = col1;
            col1 = col2;
            col2 = temp;
        }

        printf("%c%c%c%c", matrix[row1][col1], matrix[row2][col2], ' ', ' ');
    }
}

int main() {
    char key[] = "MFHIJKUNOPQZVWXYELARGBDSTBC";
    char matrix[SIZE][SIZE];
    createPlayfairMatrix(key,matrix);

    char message[] = "Must see you over Cadogan West. Coming at once.";
    playfairEncrypt(matrix, message);

    return 0;
}

OUTPUT:
BM  TP  XN  GX  JY  KY  DS  GF  GL  OG  LX  NX  SY  GK  FA  OE  GY  JO  DG  EW  
