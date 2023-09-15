#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/dsa.h>

int main() {
    // Generate a DSA key pair
    DSA *dsa = DSA_generate_parameters(1024, NULL, 0, NULL, NULL, NULL, NULL);
    DSA_generate_key(dsa);

    // Sign a message
    const char *message = "Hello, World!";
    unsigned char signature[1024];
    unsigned int sig_len;

    DSA_sign(0, (const unsigned char *)message, strlen(message), signature, &sig_len, dsa);

    // Verify the signature
    int verified = DSA_verify(0, (const unsigned char *)message, strlen(message), signature, sig_len, dsa);

    if (verified == 1) {
        printf("Signature verified successfully.\n");
    } else {
        printf("Signature verification failed.\n");
    }

    // Free resources
    DSA_free(dsa);

    return 0;
}

