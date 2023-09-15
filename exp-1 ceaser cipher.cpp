#include <stdio.h>
#include <string.h>
void encrypt(char message[], int key) {
    int messageLength = strlen(message);

    for (int i = 0; i < messageLength; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (message[i] - 'A' + key) % 26 + 'A';
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (message[i] - 'a' + key) % 26 + 'a';
        }
    }
}
void decrypt(char message[], int key) {
    encrypt(message, -key);
}

int main() {
    char message[100];
    int key;

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the key: ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}

