#include<stdio.h>
#include<stdlib.h>
int str[1000],size=0,i,times;
void share(int n){
    if(n==0){
        printf("(");
        for(i=0;i<size;i++){
            if(i==0)
                printf("%d",str[i]);
            else
                printf(",%d",str[i]);
        }
        printf(")");
        printf("\n");
        times++;
    }
    else{
        str[size++]=1;
        n-=1;
        share(n);
        n+=1;
        size--;
        if(n>=2){
            str[size++]=2;
            n-=2;
            share(n);
            n+=2;
            size--;
        }
    }
}

int main(void){
    int m;
    while(1){
        time=0;
        printf("Input the number of cookies:");
        scanf("%d",&m);
        share(m);
        printf("\n");
        printf("Total number of sharing is %d\n\n",times);
    }
    return 0;
}
