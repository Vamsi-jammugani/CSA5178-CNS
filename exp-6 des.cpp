#include <stdio.h>
#include <string.h>

int main() {
    DES_cblock key;
    DES_key_schedule schedule;
    char plaintext[] = "Hello, World!";
    char ciphertext[32]; 
    char decryptedtext[32]; 
    DES_string_to_key("MySecret", &key);
    DES_set_key(&key, &schedule);
    DES_ecb_encrypt((DES_cblock *)plaintext, (DES_cblock *)ciphertext, &schedule, DES_ENCRYPT);

    printf("Ciphertext: ");
    for (int i = 0; i < sizeof(ciphertext); i++) {
        printf("%02X", ciphertext[i]);
    }
    printf("\n");
    DES_ecb_encrypt((DES_cblock *)ciphertext, (DES_cblock *)decryptedtext, &schedule, DES_DECRYPT);

    printf("Decrypted Text: %s\n", decryptedtext);

    return 0;
}

