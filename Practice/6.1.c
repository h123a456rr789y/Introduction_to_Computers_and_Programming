#include<stdio.h>
#include<stdlib.h>

int main(void){
    int n,i,j;
    while(1){
        scanf("%d",&n);
        int a[n];
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        printf("\n");
        for(i=0;i<n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
        while(n>=1){
            a[n-1]+=a[0];
            for(i=0,j=n-1;i<=j;i++,j--){
                int tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
            n--;
            for(i=0;i<n;i++){
                printf("%d ",a[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
