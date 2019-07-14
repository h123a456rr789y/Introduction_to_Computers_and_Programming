#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void){
    while(1){
    int m,i,baby=0,adault=2;

        printf("After how many months:");
        scanf("%d",&m);
        if(m<0) {printf("Error\n\n"); continue;}
        for(i=0;i<m;i++){
            int babytmp=baby;
            baby=adault;
            adault+=babytmp;
        }
        printf("There are %d baby rabbit\n",baby);
        printf("Total: %d rabbit\n\n",adault+baby);

    }



    return 0;
}
