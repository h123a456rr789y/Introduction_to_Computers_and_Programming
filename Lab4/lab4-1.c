#include<stdio.h>

int main(void){
    int y;
    printf("Please input a year:");
    scanf("%d",&y);
    if(y%4==0 && y<=3000 && y>0){
           if (y%400!=0)
                printf("It is a ordinary year");
            else
             printf("It is a leap year");

    }
    else {
        printf("Invalid input");
    }

    return 0;
}
