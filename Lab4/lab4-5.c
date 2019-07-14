#include<stdio.h>

int main(void){
    int w1,w2,w3,a,i;
    printf("please enter the weight of 1st chicken:");
    scanf("%d",&w1);
    printf("please enter the weight of 2nd chicken:");
    scanf("%d",&w2);
    printf("please enter the weight of 1rd chicken:");
    scanf("%d",&w3);

    if(w1>w2){
        a=w2; w2=w1;w1=a;
    }
    if(w2>w3){
        a=w3; w3=w2;w2=a;
    }
    if(w1>w2){
        a=w2; w2=w1;w1=a;
    }
   /* if(w2>w3){
        a=w3; w3=w2;w3=a;
    }*/
    printf("=== After sorting ===\n%d %d %d\n",w1,w2,w3);

    i=(w1+w2+w3)/3;

    printf("===Min, Max, AVG===\n%d %d %d\n",w1,w3,i);


    if(i<10)
    {
         printf("===Ranking==\nPoor");
    }
    else if(i>=10 && i<30)
    {
         printf("===Ranking==\nUnsatisfied");
    }
    else  if(i>=30 && i<50)
    {
         printf("===Ranking==\nSo-so");
    }
    else  if(i>=50 && i<100)
    {
         printf("===Ranking==\nGood");
    }
    else
    {
       printf("===Ranking==\nExcellent");
    }
    return 0;
}
