#include<stdio.h>
#include<stdlib.h>

int power(int a,int b){
    int i,pow=1;
    for(i=0;i<b;i++){
        pow*=a;
    }
    return pow;
}

int main(void){
    int i,n,num;
    while(1){
        printf("Please input n:");
        scanf("%d",&n);
        printf("Please input the decimal number:");
        scanf("%d",&num);
        ///printf("%d",power(2,n-1));
        int a[n];
        if(num>=power(2,n-1)||num<-1*power(2,n-1)){
            printf("Overflow");
        }
        else{
            if(num<power(2,n-1)&&num>=0){
                for(i=n-1;i>=0;i--){
                    a[i]=num%2;
                    num/=2;
                }
                for(i=0;i<n;i++){
                    printf("%d",a[i]);
                }
            }
            else{
                num+=power(2,n);
                for(i=n-1;i>=0;i--){
                    a[i]=num%2;
                    num/=2;
                }
                for(i=0;i<n;i++){
                    printf("%d",a[i]);
                }
            }
        }
        printf("\n\n");
    }





    return 0;
}
