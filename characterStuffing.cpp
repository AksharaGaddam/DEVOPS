#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char a[20], fs[50] = "", t[3];
    char sd, ed, x[3], s[3], d[3], y[3];
    int i;

    printf("Enter characters to be stuffed: ");
    scanf("%s", a);
   
    printf("Enter a character that represents starting delimiter: ");
    scanf(" %c", &sd); // Use %c for single character input
   
    printf("Enter a character that represents ending delimiter: ");
    scanf(" %c", &ed);

    // Prepare the strings for stuffing
    x[0] = s[0] = sd;
    x[1] = s[1] = '\0';
    y[0] = d[0] = ed;
    d[1] = y[1] = '\0';

    strcat(fs, x);
    for (i = 0; i < strlen(a); i++) {
        t[0] = a[i];
        t[1] = '\0'; // Null-terminate for single character

        if (t[0] == sd) {
            strcat(fs, s); // Stuff starting delimiter
        } else if (t[0] == ed) {
            strcat(fs, d); // Stuff ending delimiter
        } else {
            strcat(fs, t); // Add the character
        }
    }

    strcat(fs, y); // Add ending delimiter to fs
    printf("After stuffing: %s\n", fs);

    return 0;
}
