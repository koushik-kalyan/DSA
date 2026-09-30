#include <stdio.h>
#include <string.h>

int main() {
    char s[20], ch;
    printf("Enter the string:");
    scanf("%19s", s);
    printf("Enter the character:");
    scanf(" %c", &ch);

    int len = strlen(s), n = -1;
    for (int i = 0; i < len; i++) {
        if (s[i] == ch) {
            n = i;
            break;
        }
    }

    if (n == -1) {
        printf("Character not found\n");
        return 0;
    }

    for (int i = n; i >= 0; i--)
        printf("%c", s[i]);
    for (int i = n + 1; i < len; i++)
        printf("%c", s[i]);
    printf("\n");
    return 0;
}