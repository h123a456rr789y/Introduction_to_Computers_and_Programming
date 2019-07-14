#include<stdio.h>
#include<stdlib.h>
int Cn(int n);

int main(void){
    int n,C;
    while(1){
        printf("Enter n:");
        scanf("%d",&n);
        C=Cn(n);
        printf("%dth Cathlan number is:%d\n\n", n,C);
    }
    return 0;
}
int Cn(int n){
    int i, c=0;
    if(n<=0)
        return 1;
    else{
        for(i=0;i<n;i++){
            c+=Cn(i)*Cn(n-1-i);
        }
        return (long)c;
    }
}
