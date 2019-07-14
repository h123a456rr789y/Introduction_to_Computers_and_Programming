#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    int w1,w2,w3,i,j,avg;
    printf("Please enter the weight of 1st chicken:");
    scanf("%d",&w1);
    printf("Please enter the weight of 2nd chicken:");
    scanf("%d",&w2);
    printf("Please enter the weight of 3rd chicken:");
    scanf("%d",&w3);
    printf("\n");
    avg=(w1+w2+w3)/3;
    int a[3]={w1,w2,w3};
    for(i=0;i<3;i++){
        for(j=0;j<2-i;j++){
            if(a[j]>a[j+1]){
                int tmp;
                tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
            }
    }

    }
    printf("===After sorting===\n");
    for(i=0;i<3;i++){
        printf("%d ",a[i]);
    }
    printf("\n===MIN,MAX,AVG===\n");
    printf("%d %d %d",a[0],a[2],avg);
    printf("\n===Ranking===\n");
    if(avg<10)printf("Poor\n");
    else if(avg>=10&&avg<=29)printf("Unsatisfied\n");
    else if(avg>=30&&avg<=49)printf("So-so\n");
    else if(avg>=50&&avg<=99)printf("Good\n");
    else printf("Excellent\n");




    return 0;
}

