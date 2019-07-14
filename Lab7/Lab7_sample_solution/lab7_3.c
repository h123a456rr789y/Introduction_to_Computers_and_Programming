#include <stdio.h>

int totalMove;

void move(int num, char src, char dist, char mid) {
    totalMove++;
    if(num == 1) {
        printf("Move sheet from %c to %c\n", src, dist);
        return;
    }
    move(num - 1, src, mid, dist);
    printf("Move sheet from %c to %c\n", src, dist);
    move(num - 1, mid, dist, src);
}

int main(void) {
    int num;
    totalMove = 0;
    printf("Enter the number of disks: ");
    scanf("%d", &num);
    move(num, 'A', 'C', 'B');

    printf("Need at least %d move.", totalMove);

    return 0;
}
