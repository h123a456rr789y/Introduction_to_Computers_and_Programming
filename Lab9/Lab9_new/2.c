#include <stdio.h>
#include <string.h>

int main()
{
    int i=0,j;
    char str[6][1000]={0};
    while(1)
    {
        char c[5][100]={0};
        for(i=0;;i++)
        {
            scanf("%s",c[i]);
            if(getchar()=='\n')
                break;
        }

        if(!strcmp(c[0],"assign"))
        {
            int n=c[1][3]-'0';
            if(strstr(c[1],"str")!=NULL&&c[1][3]<='5'&&c[1][3]>='0'&&c[1][4]==0&&c[3][0]==0)
            {
                if(str[n][0]==0)
                    strcpy(str[n],c[2]);
                else
                    printf("str%d has already been assign!\n",n);
            }
            else
                printf("Invalid\n");
            
        }
        else if(!strcmp(c[0],"clear"))
        {
            int n=c[1][3]-'0';
            if(strstr(c[1],"str")!=NULL&&c[1][3]<='5'&&c[1][3]>='0'&&c[1][4]==0&&c[2][0]==0)
            {
                if(str[n][0]!=0)
                    for( j=0;j<1000;j++)
                    {
                        str[n][j]=0;
                    }
                else
                    printf("Cannot clear an empty string!\n");
                
            }
            else
                printf("Invalid\n");

        }
        else if(!strcmp(c[0],"copy"))
        {
            int n1=c[1][3]-'0',n2=c[2][3]-'0';
            if(strstr(c[1],"str")!=NULL&&c[1][3]<='5'&&c[1][3]>='0'&&c[1][4]==0&&c[3][0]==0)
            {
                if(strstr(c[2],"str")!=NULL&&c[2][3]<='5'&&c[2][3]>='0'&&c[2][4]==0)
                {
                    if(str[n2][0]!=0)
                    {
                        for(j=0;j<1000;j++)
                        {
                            str[n1][j]=0;
                        }
                        
                        strcpy(str[n1],str[n2]);
                    }
                    
                    else
                        printf("Cannot copy from an empty string!\n");
                }
                else if(c[2][0]!=0)
                {
                    for(j=0;j<1000;j++)
                    {
                        str[n1][j]=0;
                    }
                    strcpy(str[n1],c[2]);
                    
                }
                else
                    printf("Invalid\n");
            }
            else
                printf("Invalid\n");

            
        }
        else if(!strcmp(c[0],"cat"))
        {
            int n1=c[1][3]-'0',n2=c[2][3]-'0';
            if(strstr(c[1],"str")!=NULL&&c[1][3]<='5'&&c[1][3]>='0'&&c[1][4]==0&&c[3][0]==0)
            {
                if(strstr(c[2],"str")!=NULL&&c[2][3]<='5'&&c[2][3]>='0'&&c[2][4]==0)
                {
                    if(str[n2][0]!=0)
                    {
                        strcat(str[n1],str[n2]);
                    }
                    
                    else
                        printf("Cannot concatenate from an empty string!\n");
                }
                else if(c[2][0]!=0)
                {
                    strcat(str[n1],c[2]);
                }
                else
                    printf("Invalid\n");
            }
            else
                printf("Invalid\n");

            
        }
        else if(!strcmp(c[0],"show")&&c[1][0]==0)
        {
            for(j=0;j<=5;j++)
                if(str[j][0]!=0)
                    printf("str%d:%s\n",i,str[j]);
        }
        else if(!strcmp(c[0],"cmp"))
        {
            int n1=c[1][3]-'0',n2=c[2][3]-'0';
            if(strstr(c[1],"str")!=NULL&&c[1][3]<='5'&&c[1][3]>='0'&&c[1][4]==0&&c[3][0]==0)
            {
                if(strstr(c[2],"str")!=NULL&&c[2][3]<='5'&&c[2][3]>='0'&&c[2][4]==0)
                {
                    if(!strcmp(str[n1],str[n2]))
                        printf("The same!\n");
                    else
                        printf("Not the same!\n");
                    
                }
                else if(c[2][0]!=0)
                {
                    if(!strcmp(str[n1],c[2]))
                        printf("The same!\n");
                    else
                        printf("Not the same!\n");
                }
                else
                    printf("Invalid\n");
            }
            else
                printf("Invalid\n");   
        }
        else
            printf("Invalid\n");
    }
}
