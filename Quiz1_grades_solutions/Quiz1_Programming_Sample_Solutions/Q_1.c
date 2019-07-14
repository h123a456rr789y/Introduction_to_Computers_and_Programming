#include <stdio.h>
#include <stdlib.h>

int main(){
    int a,b,gcd,lcm;  //gcd:greatest common divisor lcm:least common multiple
    while(1){
        printf("Please input two integers(int1 int2):");
        scanf("%d %d",&a,&b);
        if (a==0 && b==0){
            printf("Stopped!\n");
            break;
        }
        else if(a<=0)
            printf("Int1 must be greater than 0\n\n");
        else if(b<=0)
            printf("Int2 must be greater than 0\n\n");
        else{
            int a1=a,b1=b;
            while(1){
                if(a<b){
                    int tmp;
                    tmp=a;
                    a=b;
                    b=tmp;
                }
                if(a%b!=0)
                    b=a%b;
                else
                    break;
            }
            gcd=b;
            lcm=a1*b1/gcd;
            printf("the gcd of %d and %d is:%d\n",a1,b1,gcd);
            printf("the lcm of %d and %d is:%d\n",a1,b1,lcm);
            printf("\n");
        }
    }
    return 0;

}
