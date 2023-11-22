#include <stdio.h>
#include <string.h>

#define SIZE 5

char playfairMatrix[SIZE][SIZE] = {
    {'M', 'F', 'H', 'I', 'K'},
    {'U', 'N', 'O', 'P', 'Q'},
    {'Z', 'V', 'W', 'X', 'Y'},
    {'E', 'L', 'A', 'R', 'G'},
    {'D', 'S', 'T', 'B', 'C'}
};

// Function to find the position of a given character in the Playfair matrix
void findPosition(char ch, int *row, int *col) {
    if (ch == 'J') // I and J are usually treated as the same letter in Playfair cipher
        ch = 'I';

    for (*row = 0; *row < SIZE; (*row)++) {
        for (*col = 0; *col < SIZE; (*col)++) {
            if (playfairMatrix[*row][*col] == ch)
                return;
        }
    }
}

// Function to encrypt a digraph using the Playfair matrix
void encryptDigraph(char digraph[2], char cipher[2]) {
    int row1, col1, row2, col2;

    findPosition(digraph[0], &row1, &col1);
    findPosition(digraph[1], &row2, &col2);

    // Same row
    if (row1 == row2) {
        cipher[0] = playfairMatrix[row1][(col1 + 1) % SIZE];
        cipher[1] = playfairMatrix[row2][(col2 + 1) % SIZE];
    }
    // Same column
    else if (col1 == col2) {
        cipher[0] = playfairMatrix[(row1 + 1) % SIZE][col1];
        cipher[1] = playfairMatrix[(row2 + 1) % SIZE][col2];
    }
    // Different row and column
    else {
        cipher[0] = playfairMatrix[row1][col2];
        cipher[1] = playfairMatrix[row2][col1];
    }
}

// Function to encrypt a message using Playfair cipher
void playfairEncrypt(char *message) {
    int i, j;
    char digraph[2], cipher[2];

    // Adjusting the message (e.g., handling 'J' and 'I')
    for (i = 0; i < strlen(message); i += 2) {
        if (message[i] == message[i + 1]) {
            message[i + 1] = 'X';
        }
    }

    // Encrypting the message
    for (i = 0; i < strlen(message); i += 2) {
        digraph[0] = message[i];
        digraph[1] = message[i + 1];

        encryptDigraph(digraph, cipher);

        printf("%c%c %c%c ", digraph[0], digraph[1], cipher[0], cipher[1]);
    }
}

int main() {
    char message[] = "MUSTSEEYOUOVERCADOGANWESTCOMINGATONCE";
    
    printf("Original Message: %s\n", message);
    
    printf("Encrypted Message: ");
    playfairEncrypt(message);
    
    return 0;
}

OUTPUT:
Original Message: MUSTSEEYOUOVERCADOGANWESTCOMINGATONCE
Encrypted Message: MU UZ ST TB SE DL EY GZ OU PN OV NW ER LG CA TG DO TU GA ER NW OV ES LD TC BD OM UH IN FP GA ER TO HW NC QS E
