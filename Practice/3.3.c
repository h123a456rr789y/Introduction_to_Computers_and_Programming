#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    int a,b;
    printf("Please input a:");
    scanf("%d",&a);
    printf("Please input b:");
    scanf("%d",&b);
    if(a%2==0&&b%2==0){
        printf("There are %d odd number between %d and %d\n",(b-a)/2,a,b);
        printf("There are %d even numbers between %d and %d\n",(b-a)/2+1,a,b);
    }
    else if(a%2==1&&b%2==1){
        printf("There are %d odd numbers between %d and %d\n",(b-a)/2+1,a,b);
        printf("There are %d even numbers between %d and %d\n",(b-a)/2,a,b);
    }
    else {
        printf("There are %d odd numbers between %d and %d\n",(b-a)/2,a,b);
        printf("There are %d even numbers between %d and %d\n",(b-a)/2+1,a,b);
    }
    return 0;
}
