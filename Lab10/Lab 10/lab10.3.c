#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

void divid(char* email,char* id,char* title)
{
    int i=0,size=0;
    while(email[i]!='@'){
        id[size++]=email[i++];
    }
    id[size]='\0';
    size=0;
    i++;
    while(email[i]!='.'){
        title[size++]=email[i++];
    }
    title[size]='\0';
}
int main()
{
    char oper[32],sort[32],input[256],name[32],email[32],id[32],title[32],tab_name[256][32],tab_id[256][32],tab_title[256][32];
    int height,weight,tab_h[256],tab_w[256],size=0,i;
    while(1){
        scanf("%s",oper); getchar();
        if(!strcmp(oper,"assign")){
            gets(input);
            while(strlen(input)!=0){
                sscanf(input,"%s %d %d %s",name,&height,&weight,email);
                int count=0;
                if(size>0)
                    for(i=0;i<size;i++){
                        if(!strcmp(tab_name[i],name))
                            count++;
                    }
                if(count>=1)
                    printf("The name was already in the list\n");
                else{
                    divid(email,id,title);
                    strcpy(tab_name[size],name);
                    tab_h[size]=height;
                    tab_w[size]=weight;
                    strcpy(tab_id[size],id);
                    strcpy(tab_title[size],title);
                    size++;
                }
                gets(input);
            }
        }
        else if(!strcmp(oper,"show")){
            printf("Name\t\theight\tweight\tid\t\ttitle\n");
            for(i=0;i<size;i++){
                printf("%s\t\t%d\t%d\t%s\t\t%s\n",tab_name[i],tab_h[i],tab_w[i],tab_id[i],tab_title[i]);
            }
            printf("\n");
        }
        else if(!strcmp(oper,"sort")){
            int judge[size];
            for(i=0;i<size;i++){
                judge[i]=0;
            }
            scanf("%s",sort);
            if(!strcmp(sort,"Name")){
                printf("Name\t\theight\tweight\tid\t\ttitle\n");
                for(i=0;i<size;i++){
                    char cmp[32]={CHAR_MAX};
                    int j,index=0;
                    for(j=0;j<size;j++){
                        if(strcmp(tab_name[j],cmp)<0&&judge[j]==0){
                            strcpy(cmp,tab_name[j]);
                            index=j;
                        }
                    }
                    printf("%s\t\t%d\t%d\t%s\t\t%s\n",tab_name[index],tab_h[index],tab_w[index],tab_id[index],tab_title[index]);
                    judge[index]=1;
                }
                printf("\n");
            }
            else if(!strcmp(sort,"height")){
                printf("Name\t\theight\tweight\tid\t\ttitle\n");
                for(i=0;i<size;i++){
                    int min=INT_MAX,j,index=0;
                    for(j=0;j<size;j++){
                        if(tab_h[j]<min&&judge[j]==0){
                            min=tab_h[j];
                            index=j;
                        }
                    }
                    printf("%s\t\t%d\t%d\t%s\t\t%s\n",tab_name[index],tab_h[index],tab_w[index],tab_id[index],tab_title[index]);
                    judge[index]=1;
                }
                printf("\n");
            }
            else if(!strcmp(sort,"weight")){
                printf("Name\t\theight\tweight\tid\t\ttitle\n");
                for(i=0;i<size;i++){
                    int min=INT_MAX,j,index=0;
                    for(j=0;j<size;j++){
                        if(tab_w[j]<min&&judge[j]==0){
                            min=tab_w[j];
                            index=j;
                        }
                    }
                    printf("%s\t\t%d\t%d\t%s\t\t%s\n",tab_name[index],tab_h[index],tab_w[index],tab_id[index],tab_title[index]);
                    judge[index]=1;
                }
                printf("\n");
            }
            else if(!strcmp(sort,"id")){
                printf("Name\t\theight\tweight\tid\t\ttitle\n");
                for(i=0;i<size;i++){
                    char cmp[32]={CHAR_MAX};
                    int j,index=0;
                    for(j=0;j<size;j++){
                        if(strcmp(tab_id[j],cmp)<0&&judge[j]==0){
                            strcpy(cmp,tab_id[j]);
                            index=j;
                        }
                    }
                    printf("%s\t\t%d\t%d\t%s\t\t%s\n",tab_name[index],tab_h[index],tab_w[index],tab_id[index],tab_title[index]);
                    judge[index]=1;
                }
                printf("\n");
            }
            else if(!strcmp(sort,"title")){
                printf("Name\t\theight\tweight\tid\t\ttitle\n");
                for(i=0;i<size;i++){
                    char cmp[32]={CHAR_MAX};
                    int j,index=0;
                    for(j=0;j<size;j++){
                        if(strcmp(tab_title[j],cmp)<0&&judge[j]==0){
                            strcpy(cmp,tab_title[j]);
                            index=j;
                        }
                    }
                    printf("%s\t\t%d\t%d\t%s\t\t%s\n",tab_name[index],tab_h[index],tab_w[index],tab_id[index],tab_title[index]);
                    judge[index]=1;
                }
                printf("\n");
            }
            else{
                printf("Invalid\n");
            }
        }
        else if(!strcmp(oper,"clear")){
            if(size==0)
                printf("The list is already empty\n");
            else{
                for(i=0;i<size;i++){
                    tab_name[i][0]='\0';
                    tab_h[size]=0;
                    tab_w[size]=0;
                    tab_id[i][0]='\0';
                    tab_title[i][0]='\0';
                }
                size=0;
            }
        }
        else if(!strcmp(oper,"exit"))
            return 0;
        else
            printf("Invalid\n");
    }
    return 0;
}
