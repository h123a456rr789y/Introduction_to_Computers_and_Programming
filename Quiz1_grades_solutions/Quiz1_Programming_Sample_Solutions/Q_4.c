#include<stdio.h>

int main() {
    printf("Please input a number:");
    int number;
    scanf("%d", &number);

    if(number <= 0 || number > 30) {
        printf("Error input!!");
    } else {
        int current = 1;
        int end = number;
        int step = 1;

        if(number % 2 == 0) { //upside-down triangle
            current = number;
            end = 1;
            step = -1;
        }

        while(current != end + step) {
            printf("%02d ", current);
            int i = 0;
            while(i < number - current) {
                printf(" ");
                i += 1;
            }
            i = 0;
            while(i < current) {
                if(current % 2 == 1 || i < current / 2) { //odd row or first half part of even row
                    if(i % 2 == 0) {
                        printf("* ");
                    } else {
                        printf("+ ");
                    }
                } else {
                    if(i % 2 == 1) {
                        printf("* ");
                    } else {
                        printf("+ ");
                    }
                }
                i += 1;
            }
            printf("\n");
            current += step;
        }
    }

    return 0;
}
