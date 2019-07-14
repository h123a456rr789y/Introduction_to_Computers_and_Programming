#include <stdio.h>
#include <string.h>

int main()
{
    while(1)
    {
        int n=0,i;
        int k;
        char input[1000][1000]={0};
        char c[1000][1000]={0};
        printf("Please input command:\n");
        for(i=0;;i++)
        {
            scanf("%[^\n, ]",input[i]);
            if(getchar()=='\n')
                break;
        }
        for(k=0;k<=i;k++)
        {
            if(input[k][0]!=0)
            {
                strcpy(c[n],input[k]);
                n++;
            }
            
        }
        n--;
        
        if(!strcmp(c[0],"create")||!strcmp(c[0],"insert")||!strcmp(c[0],"remove"))
        {
            printf("\"%s\" is a type 2 command with preposition: \"%s\"\n",c[0],c[n-1]);
            printf("1 argument list: ");
            for(k=1;k<n-1;k++)
                if(c[k][0]!=0)
                    printf("\"%s\"",c[k]);
            printf("\nand 1 tail argument: \"%s\"",c[n]);
        }
        else if(!strcmp(c[0],"view")||!strcmp(c[0],"delete"))
        {
            printf("\"%s\" is a type 1 command\n",c[0]);
            printf("With 1 argument: \"%s\"",c[n]);
        }
        else if(!strcmp(c[0],"exit"))
        {
            return 0;
        }
        else
            printf("Unknown command \"%s\".",c[0]);
        printf("\n\n");


    }
}
