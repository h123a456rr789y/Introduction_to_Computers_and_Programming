#include<stdio.h>
#include<stdlib.h>

int main(void){
    while(1){

        float n,i,power=1.0;
        float ans=0.0;
        printf("Input a number:");
        scanf("%f",&n);
        ///printf("%f\n",n);
        for(i=1;i<=n;i++){
            power*=i;
            ans+=(1.0/power);
            ///printf("%f\n %f",ans,power);
        }
        printf("Answer: %f\n",ans+1.0);
    }
    return 0;
}
