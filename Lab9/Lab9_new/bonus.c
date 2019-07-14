#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct table
{
    char title[10];
    char name[10][10];
    char num[100][10][100];
    int row;
    int column;
};
int alive[10];
char input_old[10][100];
char input[10][100];
char str[100];
struct table Table[10];
int A,S,X;
double num;

void View(void);
void Delete(void);
void Create(void);
void Insert(void);
void Remove(void);

int main(void)
{
    int i,j,k,w;
    A=0;
    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            Table[i].title[j]='\0';
            for(k=0; k<10; k++)
            {
                Table[i].name[j][k]='\0';
            }
        }
        for(j=0; j<100; j++)
        {
            for(k=0; k<10; k++)
            {
                for(w=0; w<100; w++)
                {
                    Table[i].num[j][k][w]='\0';
                }
            }
        }
        Table[i].row=0;
        Table[i].column=0;
        alive[i]=0;
    }
    while(1)
    {
top:
        for(i=0; i<10; i++)
        {
            for(j=0; j<100; j++)
            {
                input_old[i][j]='\0';
                input[i][j]='\0';
            }
        }
        printf("There are %d table(s) in the database.\n",A);
        for(i=0;; i++)
        {
            scanf("%[^\n, ]",input_old[i]);
            if(getchar()=='\n')
            {
                break;
            }
        }
        S=0;
        for(j=0; j<=i; j++)
        {
            if(input_old[j][0]!='\0')
            {
                strcpy(input[S],input_old[j]);
                S++;
            }
        }
        S--;
        if(strcmp(input[0],"exit")==0)
        {
            return 0;
        }
        else if(strcmp(input[0],"view")==0)
        {
            View();
            goto top;
        }
        else if(strcmp(input[0],"delete")==0)
        {
            Delete();
            goto top;
        }
        else if(strcmp(input[0],"create")==0)
        {
            Create();
            goto top;
        }
        else if(strcmp(input[0],"insert")==0)
        {
            Insert();
            goto top;
        }
        else if(strcmp(input[0],"remove")==0)
        {
            Remove();
            goto top;
        }
        else
        {
            printf("Unknown command:\"%s\"\n\n",input[0]);
            goto top;
        }
    }
}
void View(void)
{
    int i,j,k;
    for(i=0; i<10; i++)
    {
        if(strcmp(Table[i].title,input[S])==0)
        {
            break;
        }
    }
    if(i>=10)
    {
        printf("Error:Can not find table:\"%s\"\n\n",input[S]);
        return ;
    }
    else
    {
        for(j=0; j<Table[i].column; j++)
        {
            printf("%10s",Table[i].name[j]);
        }
        printf("\n");
        for(j=0; j<Table[i].row; j++)
        {
            for(k=0; k<Table[i].column; k++)
            {
                num=strtod(Table[i].num[j][k],NULL);
                printf("%10.2f",num);
            }
            printf("\n");
        }
        printf("\n");
        return;
    }
}
void Delete(void)
{
    int i,j,k,w;
    for(i=0; i<10; i++)
    {
        if(strcmp(Table[i].title,input[S])==0)
        {
            break;
        }
    }
    if(i>=10)
    {
        printf("Error:Can not find table:\"%s\"\n\n",input[S]);
        return ;
    }
    else
    {
        for(j=0; j<10; j++)
        {
            Table[i].title[j]='\0';
            for(k=0; k<10; k++)
            {
                Table[i].name[j][k]='\0';
            }
        }
        for(j=0; j<100; j++)
        {
            for(k=0; k<10; k++)
            {
                for(w=0; w<100; w++)
                {
                    Table[i].num[j][k][w]='\0';
                }
            }
        }
        Table[i].row=0;
        Table[i].column=0;
        alive[i]=0;
        printf("Success!!\n\n");
        A--;
        return ;
    }
}
void Create(void)
{
    int a,i,j,k,z;
    for(i=0; i<10; i++)
    {
        if(strcmp(Table[i].title,input[S])==0)
        {
            break;
        }
    }
    if(i!=10)
    {
        printf("Error:Table \"%s\" is already exist!!\n\n",input[S]);
        return ;
    }
    else
    {
        for(a=0; a<10; a++)
        {
            if(alive[a]==0)
            {
                break;
            }
        }
        if(a>=10)
        {
            printf("The database is already full!!\n\n");
            return;
        }
        else
        {
            alive[a]=1;
            for(j=1,z=0; j<S-1; z++,j++)
            {
                strcpy(Table[a].name[z],input[j]);
            }
            Table[a].column=z;
            strcpy(Table[a].title,input[S]);
            printf("Success!!\n\n");
            A++;
            return ;
        }
    }
}
void Insert(void)
{
    int a,b,i,j,k,z,m,n;
    for(i=0; i<10; i++)
    {
        if(strcmp(Table[i].title,input[S])==0)
        {
            break;
        }
    }
    if(i>=10)
    {
        printf("Error:Table \"%s\" does not exist!!\n\n",input[S]);
        return ;
    }
    else
    {
        if(S-2!=Table[i].column)
        {
            printf("Column count not match!!\n\n");
            return;
        }
        for(j=0; j<100; j++)
        {
            if(Table[i].num[j][0][0]=='\0')
            {
                break;
            }
        }
        if(j==100)
        {
            printf("Table \"%s\" is full!!\n\n",input[S]);
            return;
        }
        else
        {
            for(a=j,b=0,k=1; k<S-1; b++,k++)
            {
                if(b>=10)
                {
                    a++;
                    b-=10;
                }
                strcpy(Table[i].num[a][b],input[k]);
            }
            Table[i].row+=1;
            printf("Success!!\n\n");
            return ;
        }
    }
}
void Remove(void)
{
    X=0;
    int i,j,k,m,n;
    for(j=0; j<100; j++)
    {
        str[j]='\0';
    }
    for(i=0; i<10; i++)
    {
        if(strcmp(Table[i].title,input[S])==0)
        {
            break;
        }
    }
    if(i>=10)
    {
        printf("Error:Table \"%s\" does not exist!!\n\n",input[S]);
        return ;
    }
    else
    {
        if(S-2!=Table[i].column)
        {
            printf("Column count not match!!\n\n");
            return;
        }
        else
        {
up:
            for(j=0; j<100; j++)
            {
                for(k=0,m=1; m<S-2; m++, k++)
                {
                    if(strcmp(Table[i].num[j][k],input[m])!=0)
                    {
                        break;
                    }
                }
                if(m>=S-2)
                {
                    for(n=0;n<10;n++)
                    {
                        strcpy(Table[i].num[j][n],str);
                    }
                    X++;
                }
            }
                printf("Success remove %d row(s) from table!!\n\n",X);
                Table[i].row-=X;
                return ;
        }
    }
}
