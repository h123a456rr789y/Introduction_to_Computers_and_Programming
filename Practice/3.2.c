#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    int int1,int2;
    float f1,f2;
    int op;
    printf("Please enter two positive intergers(int1,int2):");
    scanf("%d, %d",&int1,&int2);
    printf("Please enter two floating numbers(float1 float2):");
    scanf("%f %f",&f1,&f2);
    printf("\n\n(1) int1 %% int2\t(2)float1/float2\n");
    printf("Please choose an operation :");
    scanf("%d",&op);
    switch(op){
        case 1:
            printf("\n%d %% %d = %d",int1,int2,int1%int2);
            break;
        case 2:
            printf("\n%f / %f = %+08.3f",f1,f2,f1/f2);
            break;
        default:
            break;

    }

    return 0;
}
