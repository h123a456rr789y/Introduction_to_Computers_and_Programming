#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char token[50][50];
int token_size;
void tokenize()
{
    char ch,buf[50];
    int buf_size=0;
    token_size=0;
    while((ch=getchar())!='\n'&&(ch!=EOF)){
        if(ch==' '||ch==','){
            if(buf_size!=0){
                buf[buf_size]='\0';
                strcpy(token[token_size++],buf);
                buf_size=0;
            }
        }
        else buf[buf_size++]=ch;
    }
    if(buf_size!=0){
        buf[buf_size]='\0';
        strcpy(token[token_size++],buf);
        buf_size=0;
    }
}
int main()
{
    char ch;
    int i;
    while(1){
        printf("Please input command:\n");
        tokenize();
        if(strcmp(token[0],"create")==0||strcmp(token[0],"insert")==0||strcmp(token[0],"remove")==0){
            printf("\"%s\" is a type 2 command with preposition: \"%s\"\n",token[0],token[token_size-2]);
            printf("1 argument list:");
            for(i=1;i<token_size-2;i++)
                printf("\"%s\" ",token[i]);
            printf("\n");
            printf("and 1 tail argument: \"%s\"\n",token[token_size-1]);
        }
        else if(strcmp(token[0],"delete")==0||strcmp(token[0],"view")==0){
            printf("\"%s\" is a type 1 command\n",token[0]);
            printf("With 1 argument: \"%s\"\n",token[token_size-1]);
        }
        else if(strcmp(token[0],"exit")==0) return 0;
        else
            printf("Unknown command \"%s\"\n",token[0]);
        printf("\n");
    }
    return 0;
}