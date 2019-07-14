#include<stdio.h>
#include<stdlib.h>
int times=0;
void move(char A, char B,char C,int n){
    if(n==1){
        printf("Move sheet from %c to %c\n",A,C);
        times++;
    }
    else {
        move(A,C,B,n-1);
        printf("Move sheet from %c to %c\n",A,C);times++;
        move(B,A,C,n-1);
    }
}


int main(void){
    int n;
    printf("Enter the number of the disks:");
    scanf("%d",&n);
    move('A','B','C',n);
    printf("Need at least %d move.\n",times);
    return 0;
}
