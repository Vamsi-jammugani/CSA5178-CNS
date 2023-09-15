#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 10
int determinant(int matrix[2][2]) {
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}
int modInverse(int num) {
    for (int i = 1; i <= 26; i++) {
        if ((num * i) % 26 == 1) {
            return i;
        }
    }
    return -1; 
}
void encrypt(int keyMatrix[MAX_SIZE][MAX_SIZE], int messageMatrix[MAX_SIZE], int keySize, char encryptedMessage[]) {
    int encrypted[MAX_SIZE];

    for (int i = 0; i < keySize; i++) {
        encrypted[i] = 0;
        for (int j = 0; j < keySize; j++) {
            encrypted[i] += keyMatrix[i][j] * messageMatrix[j];
            encrypted[i] %= 26;
        }
        encryptedMessage[i] = encrypted[i] + 'A';
    }
    encryptedMessage[keySize] = '\0';
}

int main() {
    int keySize;
    int keyMatrix[MAX_SIZE][MAX_SIZE];
    char message[MAX_SIZE];
    char encryptedMessage[MAX_SIZE];

    printf("Enter the size of the key matrix (2 or 3): ");
    scanf("%d", &keySize);

    printf("Enter the key matrix:\n");
    for (int i = 0; i < keySize; i++) {
        for (int j = 0; j < keySize; j++) {
            scanf("%d", &keyMatrix[i][j]);
        }
    }

    getchar();

    printf("Enter the message to encrypt (uppercase letters only): ");
    fgets(message, sizeof(message), stdin);

    int messageMatrix[MAX_SIZE];
    int mod = keySize == 2 ? 26 : 26 * 26; 

    for (int i = 0; i < strlen(message) - 1; i++) {
        messageMatrix[i] = message[i] - 'A';
    }

    encrypt(keyMatrix, messageMatrix, keySize, encryptedMessage);

    printf("Encrypted message: %s\n", encryptedMessage);

    return 0;
}

