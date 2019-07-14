#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void){
    int i;
    int a[6];
    printf("Enter the six digit number:");
    for(i=0;i<6;i++){
        scanf("%1d",&a[i]);
    }
    printf("The reverse number is:");
    for(i=5;i>=0;i--){
        printf("%d",a[i]);
    }


    return 0;
}
