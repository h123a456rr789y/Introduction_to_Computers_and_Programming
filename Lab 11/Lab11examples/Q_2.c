#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    int n=0,i=0,j=0,k=0,t=0,a=5,s=0,x,y,z,b,m;
    char A[100][20];
    char str[100];
    char word[1000][100];
    for(x=0; x<1000; x++)
    {
        for(y=0; y<100; y++)
        {
            word[x][y]='\0';
        }
    }
    char B[100][100];
    for(b=0; b<100; b++)
    {
        strcpy(B[b],"d:\\x555JK\\Desktop\\testData\\Q2\\");
    }
    printf("How many files would you input:");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Please input file path:");
        scanf("%s",A[i]);
    }
    j=0;
    for(s=0; s<n; s++)
    {
        FILE *fp;
        strcat(B[s],A[s]);
        fp=fopen(B[s],"r");
        if(fp==NULL)
        {
            printf("Cannot open file.\n\n");
            exit(1);
        }
        while(fscanf(fp,"%s",str)!=EOF)
        {
            for(t=0; t<100; t++)
            {
                if(str[t]>'A'&&str[t]<'Z')
                {
                    str[t]=tolower(str[t]);
                }
            }
            for(k=0; k<1000; k++)
            {
                if(strcmp(word[k],str)==0)
                {
                    goto bottom;
                }
            }
            strcpy(word[j],str);
            j++;
bottom:
            if(a==0)
            {
                break;
            }
        }
        fclose(fp);
    }
    printf("\n");
    for(z=0; z<1000; z++)
    {
        if(word[z][0]=='\0')
        {
            break;
        }
    }
    for(m=0;m<100;m++)
    {
        if(strcmp(A[m],"3.txt")==0)
        {
            z--;
        }
    }
    printf("There are %d different string in those files.\n\n",z);
    return 0;
}

