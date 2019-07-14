#include<stdio.h>
#include <string.h>


int main(void)

{
    int a,b,c,d,e;
    int aa,bb,cc,dd,ee;

    printf("Please input winning number:");
    scanf("%1d%1d%1d%1d%1d",&a,&b,&c,&d,&e);
    printf("Please input your number:");
    scanf("%1d%1d%1d%1d%1d",&aa,&bb,&cc,&dd,&ee);

   if(aa==a && bb==b &&cc==c &&dd==d &&ee==e ){
    printf("You win the first prize!");
   }
   else if(aa==a && bb==b &&cc==c &&dd==d &&ee!=e){
    printf("You win the second prize!");
   }
   else if(aa!=a && bb==b &&cc==c &&dd==d &&ee==e){
    printf("You win the second prize!");
   }
    else if(aa!=a && bb==a &&cc==b &&dd==c &&ee==d){
    printf("You win the second prize!");
   }
    else if(aa==b && bb==c &&cc==d &&dd==e &&ee!=e){
    printf("You win the second prize!");
   }
   else{
    printf("Sorry, you lose! ");
   }

    return 0;

}


