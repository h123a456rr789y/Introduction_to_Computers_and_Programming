#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    int i,seconds;
    while(1){

        printf("Total seconds:");
        scanf("%d",&seconds);
        int a[4]={60,60,24,7};
        int b[4]={0};
        for(i=0;i<4;i++){
            b[i]=seconds%a[i];
            seconds/=a[i];
        }
        printf("Equal to %d week %d  day %d hour %d minute %d second\n\n",seconds,b[3],b[2],b[1],b[0]);
    }
    return 0;
}
