#include<stdio.h>

int main(void)
{
    int a,b,c,d,e,f;
    printf("Please input a:");
    scanf("%d",&a);
    printf("please input b:");
    scanf("%d",&b);
    c=(b-a)/2;
    d=(b-a)/2;
    if(a%2==1){
            if(b%2==1){
                c++;
            }
            else{
                c++;
                d++;
            }
    }
    else{
            if(b%2==1){
                c++;
                d++;
            }
            else{
                d++;
            }
    }
    printf("There are %d odd numbers between %d and %d\n",c,a,b);
    printf("There are %d even numbers between %d and %d",d,a,b);
    return 0;
}

/**
#include<stdio.h>

int main(void)
{
    int a,b,c,d,e,f;e=(b-a)/2+1;
                f=(b-a)/2+1;
    printf("Please input a:");
    scanf("%d",&a);
    printf("please input b:");
    scanf("%d",&b);
    if(a%2==1){
            if(b%2==1){
                c=(b-a)/2+1;
                d=(b-a)/2;
                printf("There are %d odd numbers between %d and %d\n",c,a,b);
                printf("There are %d even numbers between %d and %d",d,a,b);
            }
            else{e=(b-a)/2+1;
                f=(b-a)/2+1;
                c=(b-a)/2+1;
                d=(b-a)/2+1;
                printf("There are %d odd numbers between %d and %d\n",c,a,b);
                printf("There are %d even numbers between %d and %d",d,a,b);
            }
    }
    else{
            if(b%2==1){
                e=(b-a)/2+1;
                f=(b-a)/2+1;
                printf("There are %d odd numbers between %d and %d\n",e,a,b);
                printf("There are %d even numbers between %d and %d",f,a,b);
            }
            else{
                e=(b-a)/2;
                f=(b-a)/2+1;
                printf("There are %d odd numbers between %d and %d\n",e,a,b);
                printf("There are %d even numbers between %d and %d",f,a,b);
            }

    }
    return 0;
}

**/
