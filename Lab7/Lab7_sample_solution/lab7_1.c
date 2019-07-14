#include <stdio.h>

int Cn(int n);

int main(void){
    int n,C;
    while(1){
        printf("Enter n:");
        scanf("%d",&n);
        C=Cn(n);
        printf("%dth Catalan number is:%d\n\n",n,C);
    }
    return 0;
}

int Cn(int n){
    int C=0,i;
    if(n==0){
        C=1;
    }
    else{
        for(i=0;i<n;i++){
            C+=Cn(i)*Cn(n-1-i);
        }
    }
    return C;
}
