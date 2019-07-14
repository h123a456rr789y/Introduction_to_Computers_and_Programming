#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void){
    while(1){
        int num,cnt,a,i;

        float ans=1;

        printf("Input a Number:\n");
        scanf("%d",&num);

        for(cnt=1;cnt<=num;cnt++){
            a=1;
            for(i=1;i<=cnt;i++){
                a*=i;
            }
            //printf("%d\n",a);
            ans=ans+1.0/a;
        }
        printf("Answer:%f\n",ans);
    }






    return 0;
}
