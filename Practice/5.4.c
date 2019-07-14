#include<stdio.h>
#include<stdlib.h>

int main(void){
    int n,i;
    char ch;
    while(1){
        printf("Please input shift:");
        scanf("%d",&n);
        fflush(stdin);
        printf("Please input a plain text:");
        ch=getchar();
        printf("Cipher text:");
        while(ch!='\n'){
            if(isalpha(ch)){
                if(ch<='z'&&ch>='a'){
                    ch=toupper(ch);
                }
                if(ch+n>'Z'){
                    printf("%c",ch+n-26);
                    ///printf("\n");
                }
                else if(ch+n<'A'){
                    printf("%c",ch+n+26);
                }
                else{
                    printf("%c",ch+n);
                }
            }
            else
                printf("%c",ch);
            ch=getchar();
        }
        printf("\n");
    }




    return 0;
}
