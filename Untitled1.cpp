#include <stdio.h>
#include <string.h>

int main() {
    char a[20], fs[50] = "", t[2], sd, ed;
    int i;

    printf("Enter characters to be stuffed: ");
    scanf("%s", a);

    printf("Enter a character that represents starting delimiter: ");
    scanf(" %c", &sd);

    printf("Enter a character that represents ending delimiter: ");
    scanf(" %c", &ed);

    strncat(fs, &sd, 1);  // Append start delimiter
    for (i = 0; i < strlen(a); i++) {
        t[0] = a[i];
        t[1] = '\0';

        if (t[0] == sd || t[0] == ed) {
            strncat(fs, &t[0], 1); // Stuff delimiter
        }
        strcat(fs, t); // Append character
    }
    strncat(fs, &ed, 1);  // Append end delimiter

    printf("After stuffing: %s\n", fs);

    return 0;
}
