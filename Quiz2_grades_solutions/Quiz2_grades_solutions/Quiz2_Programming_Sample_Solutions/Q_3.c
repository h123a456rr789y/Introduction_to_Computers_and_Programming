#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    typedef struct{
        char id[100];
        char civil[100];
        int order;
        double discount;
    }email;
    typedef struct{
        int serial_num[9];
        char name[100];
        double prize;
        email mail;
    }profile;
    while(1){
        profile person[100];
        int ball[9];
        int n=0;
        double wp=0.0;
        char tmp_num[100]="";
        printf("Enter Total Prize:");
        gets(tmp_num);
        wp=atof(tmp_num);
        if(wp<0){
            printf("the winning prize need to be not less than 0\n");
            continue;
        }
        //scanf("%f",&wp);
        char tmp0[100]="";
        printf("Enter the winning numbers:");
        gets(tmp0);
        char *pchball;
        pchball=strtok(tmp0," ");
        while(pchball!=NULL){
            ball[n]=atoi(pchball);
            pchball=strtok(NULL," ");
            n++;
        }
        if(n<3 || n>9){
            printf("the number of the the winning numbers is wrong\n");
            continue;
        }
        /*int q=0;
        for(q=0;q<n;q++){
            printf("%d\n",ball[q]);
        }*/
        //printf("%d",n);
        //printf("%f",wp/n);
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
                    //printf("%s\n",tmp3[j]);
                    pch0 = strtok (NULL," ");

                }

                //printf("ok");
                if(!strcmp(tmp3[0],"assign")){
                    //printf("ok");

                    while(gets(tmp)){
                        char * pch;
                        int j=0;
                        int flag=0;
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
                            else if(j<=n && j>0){
                                person[i].serial_num[j-1]=atoi(pch);
                            }

                            else if(j>n){
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
                                        strcpy(person[i].mail.civil,pch3);
                                        if(!strcmp(pch3,"citizen")){
                                            person[i].mail.discount=1.0;
                                        }
                                        else if(!strcmp(pch3,"foreigner")){
                                            person[i].mail.discount=0.8;
                                        }
                                        else{
                                            ;
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
                            person[i].prize=0.0;
                            int k,l;
                            for(k=0;k<n;k++){
                                double max_p=0.0;
                                for(l=0;l<n;l++){
                                    if(person[i].serial_num[k]==ball[l]){
                                        if(max_p<(wp/n)*person[i].mail.discount){
                                            max_p=(wp/n)*person[i].mail.discount;
                                        }
                                        //break;
                                    }
                                    /*else if((person[i].serial_num[k]%(n*9))==(ball[l]%(n*9))){
                                        if(max_p<(wp/n)*(wp/n/2.0)*person[i].mail.discount){
                                            max_p=(wp/n/2.0)*person[i].mail.discount;
                                        }
                                    }*/

                                }
                                person[i].prize+=max_p;
                            }
                            i++;
                        }
                    }
                    //prinf("assign mode end\n");

                }
                else if(!strcmp(tmp3[0],"show")){
                    int k,l;
                    printf("%-10s %-8s ","Name","Tickets");
                    for(l=0;l<n;l++){
                        printf("%-4s ","");
                    }
                    printf("%-10s %-10s %-13s\n","Id","Civil","Prize");
                    for(k=0;k<i;k++){
                        printf("%-10s ",person[k].name);
                        for(l=0;l<n;l++){
                            printf("%-4d ",person[k].serial_num[l]);
                        }
                        printf("%-8s %-10s %-10s %-13f\n","",person[k].mail.id,person[k].mail.civil,person[k].prize);
                    }
                }
                else if(!strcmp(tmp3[0],"sort")){
                    profile sort[100];
                    int j,k;
                    for(j=0;j<i;j++){
                        sort[j]=person[j];
                    }
                    if(!strcmp(tmp3[1],"prize")){
                        for(j=0;j<i-1;j++){
                            for(k=j+1;k<i;k++){
                                if(sort[j].prize<sort[k].prize){
                                    profile temp;
                                    temp=sort[j];
                                    sort[j]=sort[k];
                                    sort[k]=temp;
                                }
                            }
                        }
                    }
                    else if(!strcmp(tmp3[1],"name")){
                        for(j=0;j<i-1;j++){
                            for(k=j+1;k<i;k++){
                                if(strcmp(sort[j].name,sort[k].name)>0){
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

                    int l;
                    printf("%-10s %-8s ","Name","Tickets");
                    for(l=0;l<n;l++){
                        printf("%-4s ","");
                    }
                    printf("%-10s %-10s %-13s\n","Id","Civil","Prize");
                    for(k=0;k<i;k++){
                        printf("%-10s ",sort[k].name);
                        for(l=0;l<n;l++){
                            printf("%-4d ",sort[k].serial_num[l]);
                        }
                        printf("%-8s %-10s %-10s %-13f\n","",sort[k].mail.id,sort[k].mail.civil,sort[k].prize);
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
    return 0;
}
