#include <stdio.h>

int main() {
    char ch;
    int shift;

    printf("Please input shift: ");
    scanf("%d", &shift);
    getchar();
    printf("Please input plain text: ");
    ch = getchar();
    printf("Cipher text: ");
	do {
        if(ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z') {
            if(ch < 'a') ch += 'a' - 'A';
            putchar('A' + (ch - 'a' + 26 + shift) % 26);
        } else {
            putchar(ch);
        }
    } while((ch = getchar()) != '\n');

    return 0;
}
