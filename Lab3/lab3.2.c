#include<stdio.h>

int main(void)
{
    while(1){
        int int1,int2;
        float float1,float2,g;
        int e,f;
        printf("Please enter two positive integers:");
        scanf("%d,%d",&int1,&int2);
        printf("Please enter two floating numbers:");
        scanf("%f%f",&float1,&float2);

        printf("(1) int1 %% int2    (2) float1/float2\nPlease choose an operation");
        scanf("%d",&e);
        if(e==1){
            f=int1%int2;
           printf("%d %% %d=%d",int1,int2,f);
        }
        else{
            g=float1/float2;
            printf("%f / %f=%+08.3f",float1,float2,g);
        }
    }
    return 0;
}
