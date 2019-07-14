#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    while(1){
        FILE *fptr;
        char name[100],buffer[1000+1];
        char *p;
        int psize=1;
        p=malloc(sizeof(char)*psize);
        strcpy(p,"");
        printf("Please enter the input file name:");
        scanf("%s",name);
        fptr=fopen(name,"r");
        if(fptr==NULL){
            printf("No such file existed.\n");
        }
        else{
            FILE *optr=NULL;
            int rep=-1;
            while(fgets(buffer,1000,fptr)!=NULL){
                if(buffer[0]=='>'){
                    if(optr!=NULL){
                        fprintf(optr,"%s\n",p);
                        strcpy(p,"");
                        fclose(optr);
                    }
                    char tmp[100],*pch;
                    pch=strtok(buffer,"> ");
                    int count=0;
                    while(pch!=NULL){
                        strcpy(tmp,pch);

                        pch=strtok(NULL,"> \n");
                        if(count==0){
                            strcat(tmp,".txt");
                            optr=fopen(tmp,"w");
                        }
                        else{
                            fprintf(optr,"%s\n",tmp);
                        }
                        count++;
                    }
                }
                else{
                    if(optr!=NULL){
                        if(buffer[0]=='-'){
                            strcpy(p,"");
                            int len=strlen(buffer);
                            int i=0;
                            for(i=0;i<len;i++){
                                buffer[i]=buffer[i+1];
                            }
                        }
                        else if(buffer[0]>='0' && buffer[0]<='9'){
                            rep=buffer[0]-'0';
                            int len=strlen(buffer);
                            int i=0;
                            for(i=0;i<len;i++){
                                buffer[i]=buffer[i+1];
                            }
                        }
                        if(rep==-1){
                            if(psize<=(strlen(p)+strlen(buffer))){
                                psize=strlen(p)+strlen(buffer)+1;
                            }
                            char *tmp;
                            tmp=malloc(sizeof(char)*(strlen(p)+1));
                            strcpy(tmp,p);

                            p=malloc(sizeof(char)*psize);
                            strcpy(p,tmp);
                            strncat(p,buffer,strlen(buffer)-1);
                        }
                        else{
                            int i=0;
                            for(i=0;i<rep;i++){
                                if(psize<=(strlen(p)+strlen(buffer))){
                                    psize=strlen(p)+strlen(buffer)+1;
                                }
                                char *tmp;
                                tmp=malloc(sizeof(char)*(strlen(p)+1));
                                strcpy(tmp,p);

                                p=malloc(sizeof(char)*psize);
                                strcpy(p,tmp);
                                strncat(p,buffer,strlen(buffer)-1);

                            }
                            rep=-1;
                        }


                    }
                }
            }
            fprintf(optr,"%s\n",p);
            strcpy(p,"");
            fclose(fptr);
            fclose(optr);
            printf("finished\n");
        }
    }
    return 0;
}
