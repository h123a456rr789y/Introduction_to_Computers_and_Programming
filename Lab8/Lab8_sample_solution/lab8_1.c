#include<stdio.h>
int check(char a[],char b[]);
int main(){

    while(1){
        char s1[100]="",s2[100]="";
        int i;
        gets(s1);
        gets(s2);
        i=check(s1,s2);
        if(i==0)
            printf("String1 is not a substring of String2\n");
        else if(i==1)
            printf("String1 is a Non-continuous substring of String2\n");
        else if(i==2)
            printf("String1 is a Continuous substring of String2\n");
        printf("\n");
    }
}

int check(char a[],char b[]){
    int i=0,j=0,k=0,flag=0;
    while(1){
        if(a[i]=='\0'){
            flag=1;
            break;
        }
        else if(a[i]==b[j]){
            i++;
        }
        if(b[j]=='\0'){
            break;
        }
        j++;
    }
    if(flag==1){
        int tmp=0;
        i=0;
        j=0;
        while(1){
            if(a[i]=='\0'){
                flag=2;
                break;
            }
            else if(a[i]==b[j]){
                if(i==0){
                    tmp=j;
                }
                i++;
            }
            else{
                if(i!=0){
                    j=tmp;
                }
                i=0;

            }
            if(b[j]=='\0'){
                break;
            }
            j++;
        }
    }
    return flag;
}
