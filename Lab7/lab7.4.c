#include<stdio.h>
#include<stdlib.h>
int cnt=0;
void towerOfHanoi(int n, char a, char b, char c)
{
    if (n == 1)
    {
        printf("\nMove sheet 1 from %c to 10%c", a, b);
        cnt++;
        return;
    }
    towerOfHanoi(n-1, a, c, b);
    printf("\nMove sheet %d from %c to %c", n, a, b);
    cnt++;
    towerOfHanoi(n-1, c, b, a);
}

int main()
{
    int n;
    printf("Enter the number of disks:");
    scanf("%d",&n);
    towerOfHanoi(n, 'A', 'C', 'B');
    printf("\nNeed at least %d move.",cnt);
    return 0;
}
