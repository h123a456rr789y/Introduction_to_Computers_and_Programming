#include<stdio.h>
int main(void)
{
    int i,a,b,c,d,e,f,j;
    printf("Enter the six digit number:\n");
    scanf("%d",&i);
    a=i%10;
    b=(i%100)/10;
    c=(i%1000)/100;
    d=(i%10000)/1000;
    e=(i%100000)/10000;
    f=(i%1000000)/100000;
    j=a*100000+b*10000+c*1000+d*100+e*10+f*1;

    printf("The reverse number is:%06d",j);

    return 0;
}
