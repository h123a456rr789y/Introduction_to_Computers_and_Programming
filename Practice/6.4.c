#include<stdio.h>
#include<stdlib.h>


char text[100];

int main(void){
    while(1){
        printf("Please input text:");
        char ch;
        int i=0,j,k;
        ch=getchar();
        while(ch!='\n'){
           ///printf("%c\n",ch);
            text[i++]=ch;
            if(ch=='#'){
                for(j=0,k=i-2;j<k;j++,k--){
                    int tmp=text[j];
                    text[j]=text[k];
                    text[k]=tmp;
                }
            }
            ch=getchar();
        }
        text[i]='\0';
        puts(text);
    }
    return 0;
}
