#include<stdio.h>

int main(void)
{
    float a;
    int b;
    printf("Enter a float number:");
    scanf("%f",&a);
    b=a+0.5;
    printf("The number after rounding is:%d",b);
    return 0;
}
