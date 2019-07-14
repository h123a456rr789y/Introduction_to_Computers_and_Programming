#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(void){
   int b;
   scanf("%d",&b);
   int a[b], i, j;
   for(i=0;i<b;i++){
    scanf("%d",&a[i]);
    }
    printf("\n");
    for(i=0;i<b;i++){
        printf("%d ",a[i]);
    }
    printf("\n");

   while(b!=1){
        a[b-1]=a[0]+a[b-1];
        for(i=0,j=b-1;i<=j;i++,j--){
            int tmp;
            tmp=a[j];
            a[j]=a[i];
            a[i]=tmp;
        }
        for(i=0;i<b-1;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
        b--;
   }
    return 0;
}
