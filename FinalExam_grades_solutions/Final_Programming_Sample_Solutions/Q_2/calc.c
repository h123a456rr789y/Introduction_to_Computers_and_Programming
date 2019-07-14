#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"
#include "stack.h"
int calc(char s[]){
    char *pch;
    pch=strtok(s," \n");
    while(pch!=NULL){
        if(!strcmp(pch,"+") || !strcmp(pch,"-") || !strcmp(pch,"*") || !strcmp(pch,"/")){
            if(is_empty()){
                printf("Invalid!\n");
                return 1;
            }
            double v1=top_val();
            char tmp1[256];
            strcpy(tmp1,top_s());
            pop();
            if(is_empty()){
                printf("Invalid!\n");
                return 1;
            }
            double v2=top_val();
            char tmp2[256];
            strcpy(tmp2,top_s());
            pop();
            char tmp3[256]="(";
            strcat(tmp3,tmp2);
            strcat(tmp3,pch);
            strcat(tmp3,tmp1);
            strcat(tmp3,")");
            if(!strcmp(pch,"+")){
                v2+=v1;
            }
            else if(!strcmp(pch,"-")){
                v2-=v1;
            }
            else if(!strcmp(pch,"*")){
                v2*=v1;
            }
            else{
                v2/=v1;
            }
            push(tmp3,v2);
        }
        else{
            //printf("%f",atof(pch));
            push(pch,atof(pch));
        }

        pch=strtok(NULL," \n");
    }
    double tmpv=top_val();
    char tmps[256];
    strcpy(tmps,top_s());
    pop();
    if(!is_empty()){
        printf("Invalid\n");
        return 1;
    }

    printf("Result:%f\nInfix:%s\n",tmpv,tmps);
    return 0;
}
