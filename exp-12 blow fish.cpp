#include <stdio.h>
#include <string.h>
#include <openssl/blowfish.h>

int main() {
    BF_KEY key;
    unsigned char key_data[] = "MySecretKey"; // Replace with your secret key
    unsigned char plaintext[] = "Hello, World!";
    unsigned char ciphertext[64];
    unsigned char decryptedtext[64];

    // Set up the Blowfish key
    BF_set_key(&key, strlen((const char *)key_data), key_data);

    // Encrypt the data
    BF_ecb_encrypt(plaintext, ciphertext, &key, BF_ENCRYPT);

    printf("Ciphertext: ");
    for (int i = 0; i < sizeof(ciphertext); i++) {
        printf("%02X", ciphertext[i]);
    }
    printf("\n");

    // Decrypt the data
    BF_ecb_encrypt(ciphertext, decryptedtext, &key, BF_DECRYPT);

    printf("Decrypted Text: %s\n", decryptedtext);

    return 0;
}

