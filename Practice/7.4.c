#include<stdio.h>
#include<stdlib.h>

void sort(int n){
    int i,j,k,l=0;
    for(i=1;i<10;i++){
        printf("%d ",i);
        j=i*10;
        if(j<=n){
            for(k=0;k<10;k++){
                l=j;
                l+=k;
                if(l<=n)
                printf("%d ",l);

            }
            l*=10;
        }
    }
}


int main(void){
    int n;
    while(1){
        printf("please input n:");
        scanf("%d",&n);
        sort(n);
        printf("\n");
    }
    return 0;
}
