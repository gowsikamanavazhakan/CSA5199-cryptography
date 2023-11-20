#include <stdio.h>
#include <string.h>

// Function to encrypt the message using the Hill cipher
void hillCipherEncrypt(char message[], int keyMatrix[2][2]) {
    int len = strlen(message);
    int encrypted[len];
	int i;
    for (i = 0; i < len; i += 2) {
        // Split the message into pairs
        int pair1 = message[i] - 'a';
        int pair2 = (i + 1 < len) ? message[i + 1] - 'a' : 'x' - 'a'; // 'x' is the padding character

        // Perform the Hill cipher encryption
        encrypted[i] = (keyMatrix[0][0] * pair1 + keyMatrix[0][1] * pair2) % 26;
        encrypted[i + 1] = (keyMatrix[1][0] * pair1 + keyMatrix[1][1] * pair2) % 26;
    }

    printf("Encrypted message: ");
    for (i = 0; i < len; i++) {
        printf("%c", encrypted[i] + 'a');
    }
    printf("\n");
}

int main() {
    char message[] = "meetmeattheusualplaceattenratherthaneightoclock";
    int keyMatrix[2][2] = {{9, 4}, {5, 7}};
	int i;
    // Convert the message to lowercase
    for ( i = 0; message[i] != '\0'; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = message[i] - 'A' + 'a';
        }
    }

    hillCipherEncrypt(message, keyMatrix);

    return 0;
}
output:
Encrypted message: ukixukydromeiwszxwiokunukhxhroajroanqyebtlkjega
