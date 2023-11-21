#include <stdio.h>
#include <string.h>

// Function to perform Hill cipher encryption
void hillCipherEncrypt(int key[3][3], char plaintext[], char ciphertext[]) {
	int i,j,k;
    int len = strlen(plaintext);
    for (i = 0; i < len; i += 3) {
        int block[3] = {0};

        // Convert the current block of plaintext to numbers
        for (j = 0; j < 3 && i + j < len; j++) {
            block[j] = plaintext[i + j] - 'A';
        }

        // Perform the encryption for the block
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                ciphertext[i + j] += key[j][k] * block[k];
            }
            ciphertext[i + j] = (ciphertext[i + j] % 26 + 26) % 26; // Ensure it's in the range [0, 25]
            ciphertext[i + j] += 'A'; // Convert back to letters
        }
    }
}

// Function to perform Hill cipher decryption
void hillCipherDecrypt(int key[3][3], char ciphertext[], char decryptedtext[]) {
	int i,j,k;
    int len = strlen(ciphertext);
    int determinant = key[0][0] * (key[1][1] * key[2][2] - key[1][2] * key[2][1]) -
                     key[0][1] * (key[1][0] * key[2][2] - key[1][2] * key[2][0]) +
                     key[0][2] * (key[1][0] * key[2][1] - key[1][1] * key[2][0]);

    int determinantInverse = 0;
    for (i = 0; i < 26; i++) {
        if ((determinant * i) % 26 == 1) {
            determinantInverse = i;
            break;
        }
    }

    int adjugate[3][3] = {
        {key[1][1] * key[2][2] - key[1][2] * key[2][1], key[0][2] * key[2][1] - key[0][1] * key[2][2], key[0][1] * key[1][2] - key[0][2] * key[1][1]},
        {key[1][2] * key[2][0] - key[1][0] * key[2][2], key[0][0] * key[2][2] - key[0][2] * key[2][0], key[0][2] * key[1][0] - key[0][0] * key[1][2]},
        {key[1][0] * key[2][1] - key[1][1] * key[2][0], key[0][1] * key[2][0] - key[0][0] * key[2][1], key[0][0] * key[1][1] - key[0][1] * key[1][0]}
    };

    // Calculate the adjugate modulo 26
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            adjugate[i][j] = (adjugate[i][j] % 26 + 26) % 26;
        }
    }

    // Multiply the adjugate by the determinant inverse
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            adjugate[i][j] = (adjugate[i][j] * determinantInverse) % 26;
        }
    }

    for (i = 0; i < len; i += 3) {
        int block[3] = {0};

        // Convert the current block of ciphertext to numbers
        for (j = 0; j < 3 && i + j < len; j++) {
            block[j] = ciphertext[i + j] - 'A';
        }

        // Perform the decryption for the block
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                decryptedtext[i + j] += adjugate[j][k] * block[k];
            }
            decryptedtext[i + j] = (decryptedtext[i + j] % 26 + 26) % 26; // Ensure it's in the range [0, 25]
            decryptedtext[i + j] += 'A'; // Convert back to letters
        }
    }
}

int main() {
    // Define the Hill cipher key (3x3 matrix)
    int key[3][3] = {
        {6, 24, 1},
        {13, 16, 10},
        {20, 17, 15}
    };

    char plaintext[] = "HELLOHILLCIPHER";
    char ciphertext[100] = {0};
    char decryptedtext[100] = {0};

    printf("Original message: %s\n", plaintext);

    // Encrypt the message
    hillCipherEncrypt(key, plaintext, ciphertext);
    printf("Encrypted message: %s\n", ciphertext);

    // Decrypt the message
    hillCipherDecrypt(key, ciphertext, decryptedtext);
    printf("Decrypted message: %s\n", decryptedtext);

    return 0;
}

OUTPUT:
Original message: HELLOHILLCIPHER
Encrypted message: XJNBDZPIAPWTDRD
Decrypted message: ZIFRGBITDMSPNGJ
