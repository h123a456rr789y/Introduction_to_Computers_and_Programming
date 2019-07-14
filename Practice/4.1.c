#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    int n;
    while(1){

        printf("Please input a year:");
        scanf("%d",&n);
        if(n%4==0){
            if(n%400==0&&n%100==0)
                printf("It's an leap year\n");
            else if(n%100==0)
                printf("It's an ordinary year\n");
            else
                printf("It's an leap year\n");
        }
        else printf("It's an ordinary year\n");
    }
    return 0;
}
