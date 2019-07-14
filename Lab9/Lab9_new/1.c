#include<stdio.h>
#define MAX_TABLE_SZ 10
typedef struct
{
    int key;
    int value;
}HashEntry;

typedef struct
{
    int table_size;
    HashEntry HE[MAX_TABLE_SZ];
}HashTable;

HashTable Add(HashTable ht,int p[],int k,int v,int x);
HashTable Remove(HashTable ht,int p[]);
void Show(HashTable ht);

int main(void)
{
    int i;
	int p[11]={0};
    HashTable ht;
    printf("Input the size of the hash table:\n-");
    scanf("%d",&ht.table_size);
    for(i=0;i<ht.table_size;i++)
    {
        ht.HE[i].key=-1;
        ht.HE[i].value=-1;
    }
    while(1)
    {
        int c;
        printf("Input the operation: (1) Add an Entry (2) Remove an Entry by Key (3) Show\n-");
        scanf("%d",&c);
        if(c==1)
        {
            int x,k,v;
            printf("Input the key and the value of the entry: ");
            scanf("%d,%d",&k,&v);
            x=k%ht.table_size;
            ht=Add(ht,p,k,v,x);
            
        }
        else if(c==2)
        {
            ht=Remove(ht,p);
        }
        else if(c==3)
        {
            Show(ht);
        }
        else
            printf("Invalid\n");
    }
    return 0;
}
void Show(HashTable ht)
{
	int i;
    printf("======================\n");
    for(i=0;i<ht.table_size;i++)
    {
        printf("[00%d]\t%d\t%d\n",i,ht.HE[i].key,ht.HE[i].value);
    }
    printf("======================\n");
}
HashTable Remove(HashTable ht,int p[])
{
    int k,i;
    printf("Please input the key of the entry: ");
    scanf("%d",&k);
    for(i=0;i<ht.table_size;i++)
    {
        if(ht.HE[i].key==k)
            break;
    }
    if(i==ht.table_size)
        printf("[INFO] The KEY is not in the hash table.\n");
    else
    {
        ht.HE[i].key=-1;
        ht.HE[i].value=-1;
        p[i]=0;
        printf("[INFO] The entry %d has been removed.\n",k);
    }
    return ht;
}
HashTable Add(HashTable ht,int p[],int k,int v,int x)
{
    int i;
	int t=0;
    for(i=0;i<ht.table_size;i++)
    {
        if(p[i]==1)
            t++;
    }
    if(t==ht.table_size)
    {
        printf("[INFO] The space is not enough.\n");
    }
    else
    {
        if(p[x]==1)
        {
            x=(x+1)%ht.table_size;
            ht=Add(ht,p,k,v,x);
        }
        else
        {
            ht.HE[x].key=k;
            ht.HE[x].value=v;
            p[x]=1;
            printf("[INFO] The entry %d has been added.\n",k);
        }   
    }
    return ht;   
}
