#include<stdio.h>
#include<stdlib.h>

int main(void){
    int mon,baby,adault,cnt,a;

    while(1){
        printf("After how many months:");
        scanf("%d",&mon);

        if(mon>=0){
            baby=0;
            adault=2;
            for(cnt=0;cnt<mon;cnt++){
                a=baby;
                baby=adault;
                adault=a+baby;
                }
            printf("There are %d baby rabbit\n",baby);
            printf("Total:%d rabbit\n",adault+baby);
        }
        else{
            printf("Error\n");
        }
    }
    return 0;
}
