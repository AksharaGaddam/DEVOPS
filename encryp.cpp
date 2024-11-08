#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    char a[] = "0ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int n, i, j, s, p, q, d, e, m1;
    unsigned long int k2;
    double l1, l2;
    char p1[30], c[30];

    printf("Enter two prime numbers p and q:\n");
    scanf("%d %d", &p, &q);
    do {
        n = p * q;
        if (n < 26) {
            printf("\n n value is not large enough.\nPlease select p, q values such that p*q is greater than 26:\n");
            scanf("%d %d", &p, &q);
        }
    } while (n < 26);

    int z = (p - 1) * (q - 1);
    printf("Enter the value of d:\n");
    scanf("%d", &d);

    // Finding e such that (d * e) % z = 1
    for (j = 1; j < z; j++) {
        if ((j * d) % z == 1) {
            e = j;
            break;
        }
    }

    printf("n = %d, z = %d, e = %d\n", n, z, e);
    printf("ENCRYPTION - CIPHERTEXT\n");

    printf("Enter the plaintext:\n");
    scanf("%s", p1);

    // Encryption
    for (i = 0; i < strlen(p1); i++) {
        for (j = 1; j < strlen(a); j++) {
            if (a[j] == p1[i]) {
                s = j;
                break;
            }
        }
        l1 = pow(s, e);
        k2 = fmod(l1, n);
        c[i] = (char)k2 + '0'; // Storing cipher character as a char
        printf("%lu ", k2); // Print the cipher number
    }

    printf("\nCiphertext: ");
    for (i = 0; i < strlen(p1); i++) {
        printf("%d ", c[i] - '0'); // Print as integer values
    }
    printf("\n");

    // Decryption
    printf("DECRYPTION - PLAINTEXT\n");
    for (i = 0; i < strlen(p1); i++) {
        l2 = pow(c[i] - '0', d); // Decrypting
        m1 = fmod(l2, n);
        printf("%c", a[m1]); // Output plaintext character
    }

    printf("\n");
    return 0;
}
     
