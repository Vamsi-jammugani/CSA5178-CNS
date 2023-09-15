#include <stdio.h>
#include <string.h>
#include <ctype.h>0
#define SIZE 5 
void prepareKey(char *key, char *preparedKey) {
    int i, j, k = 0;
    char tempKey[26] = {0};
    for (i = 0; i < strlen(key); i++) {
        if (key[i] != ' ') {
            if (!tempKey[key[i] - 'A']) {
                preparedKey[k++] = key[i];
                tempKey[key[i] - 'A'] = 1;
            }
        }
    }
    for (i = 0; i < 26; i++) {
        if (i != ('J' - 'A') && !tempKey[i]) {
            preparedKey[k++] = i + 'A';
        }
    }
}
void generateMatrix(char *preparedKey, char matrix[SIZE][SIZE]) {
    int i, j, k = 0;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            matrix[i][j] = preparedKey[k++];
        }
    }
}
void findPosition(char matrix[SIZE][SIZE], char letter, int *row, int *col) {
    int i, j;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (matrix[i][j] == letter) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}
void encryptDigraph(char matrix[SIZE][SIZE], char digraph[2], char encryptedDigraph[2]) {
    int row1, col1, row2, col2;

    findPosition(matrix, digraph[0], &row1, &col1);
    findPosition(matrix, digraph[1], &row2, &col2);

    if (row1 == row2) {
        encryptedDigraph[0] = matrix[row1][(col1 + 1) % SIZE];
        encryptedDigraph[1] = matrix[row2][(col2 + 1) % SIZE];
    } else if (col1 == col2) {
        encryptedDigraph[0] = matrix[(row1 + 1) % SIZE][col1];
        encryptedDigraph[1] = matrix[(row2 + 1) % SIZE][col2];
    } else {
        encryptedDigraph[0] = matrix[row1][col2];
        encryptedDigraph[1] = matrix[row2][col1];
    }
}
void cleanMessage(char *message) {
    int i, j = 0;
    char cleanedMessage[strlen(message) + 1];

    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            cleanedMessage[j++] = toupper(message[i]);
        }
    }
    cleanedMessage[j] = '\0';
    strcpy(message, cleanedMessage);
}
void encryptMessage(char matrix[SIZE][SIZE], char *message, char *encryptedMessage) {
    int i;
    char encryptedDigraph[2];
    
    for (i = 0; i < strlen(message); i += 2) {
        encryptedDigraph[0] = message[i];
        encryptedDigraph[1] = (i + 1 < strlen(message)) ? message[i + 1] : 'X';
        
        encryptDigraph(matrix, encryptedDigraph, encryptedDigraph);
        
        encryptedMessage[i] = encryptedDigraph[0];
        encryptedMessage[i + 1] = encryptedDigraph[1];
    }
    encryptedMessage[i] = '\0';
}

int main() {
    char key[100];
    char message[100];
    char preparedKey[26];
    char matrix[SIZE][SIZE];
    char encryptedMessage[100];
    
    printf("Enter the key (only alphabetic characters, no spaces): ");
    fgets(key, sizeof(key), stdin);
    key[strlen(key) - 1] = '\0'; 
    
    prepareKey(key, preparedKey);
    generateMatrix(preparedKey, matrix);

    printf("Enter the message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    message[strlen(message) - 1] = '\0'; 
    
    cleanMessage(message);
    encryptMessage(matrix, message, encryptedMessage);
    
    printf("Encrypted message: %s\n", encryptedMessage);
    
    return 0;
}

