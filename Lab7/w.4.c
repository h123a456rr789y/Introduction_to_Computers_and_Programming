#include <stdio.h>

void sort(n){
    int i,k;
    for(i=1;i<=9;i++){
        int j=1;
        while (j<=n){
            for(k=0 ; k<j ; k++){
                if(k+j*i<=n){
                    printf("%d ",k+j*i);
                }
            }
            j*=10;
        }
    }
}

int main() {
    while(1){
    printf("please input n:");
    int n;
    scanf("%d",&n);
        sort(n);
    }
    return 0;
}
