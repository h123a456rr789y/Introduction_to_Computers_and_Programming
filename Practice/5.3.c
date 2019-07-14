#include<stdio.h>
#include<stdlib.h>

int main(void){
    char ch;
    for(;;){
        int n=0,i;

        printf("Please input a plain text:");
        ch=getchar();
        while(ch!='\n'){
            if(isdigit(ch)){
                n*=10;
                n+=ch-'0';
            }
            else{
                for(i=0;i<n;i++){
                    printf("%c",ch);
                }
                n=0;
            }
            ch=getchar();
        }
        printf("\n");
    }
    return 0;
}
