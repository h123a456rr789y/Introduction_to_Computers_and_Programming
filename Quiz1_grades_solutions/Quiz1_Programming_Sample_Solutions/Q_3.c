#include <stdio.h>
#include <stdlib.h>

int main(){
    int input=0;
    while(1){
        int digi=0,p=1,flag=1,mirror=1;
        printf("Please input the number:");
        scanf("%d",&input);
        if(input<0){
            printf("Over\n");
            break;
        }
        int cnt_t=input;
        while(cnt_t!=0){
            cnt_t=cnt_t/10;
            digi++;
        }
        while(digi>0){
            int i=0,tmp=1,a=0,b=0;
            while(i<(digi-1)){
                tmp*=10;
                i++;
            }
            a=input%10;
            b=input/tmp;
            input-=b*tmp;
            input/=10;
            if(a==b){
                flag=1;
                if(a!=0 && a!=8)
                    mirror=0;
            }
            else{
                flag=0;
                break;
            }
            digi-=2;
        }
        if(flag==1 && mirror==1){
            printf("This is a Mirrored palindromic number\n");
        }
        else if(flag==1 && mirror==0){
            printf("This is a Palindromic number\n");
        }
        else
            printf("This is Not a Palindromic number\n");
        printf("\n");
    }
    return 0;
}
