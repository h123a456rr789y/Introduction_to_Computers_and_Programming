#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    typedef struct{
        char id[100];
        char title[100];
        int order;
    }email;
    typedef struct{
        int height,weight;
        char name[100];
        email mail;
    }profile;
    profile person[100];
    int n;
    while(1){
        char tmp[100]="",tmp2[100]="";
        int i=0;
        while(gets(tmp2)){
            char tmp3[2][100]={"",""};
            char *pch0;
            int j=0;
            pch0=strtok(tmp2," ");
            for(j=0;j<2;j++){
                if(pch0==NULL){
                    break;
                }
                strcpy(tmp3[j],pch0);
                printf("%s\n",tmp3[j]);
   	            pch0 = strtok (NULL," ");
            }
            //printf("ok");
            if(!strcmp(tmp3[0],"assign")){
                //printf("ok");
                while(gets(tmp)){
                    int flag=0;
                    char * pch;
                    int j=0;
                    if(tmp[0]=='\0'){
                        break;
                    }
                    //char a[20][100]
                    pch = strtok(tmp," ");
                    while (pch != NULL)
                    {
                        if(j==0){
                            int m=0;
                            for(m=0;m<i;m++){
                                if(!strcmp(person[m].name,pch)){
                                    printf("The name was already in the list\n");
                                    //i--;
                                    flag=1;
                                    break;
                                }
                            }
                            if(flag==1) break;
                            strcpy(person[i].name,pch);
                        }
                        else if(j==1){
                            person[i].height=atoi(pch);
                        }
                        else if(j==2){
                            person[i].weight=atoi(pch);
                        }
                        else if(j==3){
                            int m=0;
                            char * pch2;
                            pch2 = strtok(pch,"@");
                            while(pch2 != NULL){
                                if(m==0){
                                    strcpy(person[i].mail.id,pch2);
                                }
                                else if(m==1){
                                    int o=0;
                                    char *pch3;
                                    pch3 = strtok(pch2,".");
                                    strcpy(person[i].mail.title,pch3);
                                    if(!strcmp(pch3,"ceo")){
                                        person[i].mail.order=0;
                                    }
                                    else if(!strcmp(pch3,"manager")){
                                        person[i].mail.order=1;
                                    }
                                    else if(!strcmp(pch3,"employee")){
                                        person[i].mail.order=2;
                                    }
                                    else{
                                        person[i].mail.order=99;
                                    }
                                }
                                pch2 = strtok (NULL,"@");
                                m++;

                            }

                            //strcpy(person[i].mail.id,pch);
                        }

                        pch = strtok (NULL," ");
                        j++;
                    }
                    if(flag==0){
                        i++;
                    }
                }
                //prinf("assign mode end\n");

            }
            else if(!strcmp(tmp3[0],"show")){
                int k;
                printf("%-10s %-8s %-8s %-10s %-10s\n","Name","height","weight","id","title");
                for(k=0;k<i;k++){
                    printf("%-10s %-8d %-8d %-10s %-10s\n",person[k].name,person[k].height,person[k].weight,person[k].mail.id,person[k].mail.title);
                }
            }
            else if(!strcmp(tmp3[0],"sort")){
                profile sort[100];
                int j,k;
                for(j=0;j<i;j++){
                    sort[j]=person[j];
                }
                if(!strcmp(tmp3[1],"height")){
                    for(j=0;j<i-1;j++){
                        for(k=j+1;k<i;k++){
                            if(sort[j].height<sort[k].height){
                                profile temp;
                                temp=sort[j];
                                sort[j]=sort[k];
                                sort[k]=temp;
                            }
                        }
                    }
                }
                else if(!strcmp(tmp3[1],"weight")){
                    for(j=0;j<i-1;j++){
                        for(k=j+1;k<i;k++){
                            if(sort[j].weight>sort[k].weight){
                                profile temp;
                                temp=sort[j];
                                sort[j]=sort[k];
                                sort[k]=temp;
                            }
                        }
                    }
                }
                else if(!strcmp(tmp3[1],"title")){
                    for(j=0;j<i-1;j++){
                        for(k=j+1;k<i;k++){
                            if(sort[j].mail.order>sort[k].mail.order){
                                profile temp;
                                temp=sort[j];
                                sort[j]=sort[k];
                                sort[k]=temp;
                            }
                        }
                    }
                }
                else{
                    printf("invalid\n");
                    continue;
                }

                printf("%-10s %-8s %-8s %-10s %-10s\n","Name","height","weight","id","title");
                for(k=0;k<i;k++){
                    printf("%-10s %-8d %-8d %-10s %-10s\n",sort[k].name,sort[k].height,sort[k].weight,sort[k].mail.id,sort[k].mail.title);
                }
            }
            else if(!strcmp(tmp3[0],"")){
                ;
            }
            else if(!strcmp(tmp3[0],"clear")){
                profile cl;
                for(j=0;j<i;j++){
                    person[j]=cl;
                }
                i=0;
            }
            else{
                printf("invalid\n");
            }
        }
    }

}
