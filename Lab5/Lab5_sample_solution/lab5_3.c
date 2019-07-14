#include <stdio.h>

int main() {
    char ch;

    printf("Please input plain text: ");
    ch = getchar(); //scanf("%c", &ch);

    printf("output text: ");
    int repeatTimes = 0;
    do {
        if(ch >= '0' && ch <= '9') {
            repeatTimes = repeatTimes * 10 + (ch - '0');
        } else {
            int i;
            for(i = 0; i < repeatTimes; i++) {
                putchar(ch);
            }
            repeatTimes=0;
        }
    } while((ch = getchar()) != '\n');

    return 0;
}
