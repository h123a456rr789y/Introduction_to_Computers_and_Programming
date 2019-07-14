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


void put(HashTable *HT);
void rm(HashTable *HT);
void show(HashTable HT);
void init(HashTable *HT);


int main(void)
{
    HashTable HT;
    init(&HT);
    printf("Input the size of the hash table \n- ");
    scanf("%d", &(HT.table_size));

    while(1)
    {
        int op;
        printf("Input the operation: (1) Add an entry; (2) Remove an entry by key; (3) Show \n- ");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
                put(&HT);
                break;
            case 2:
                rm(&HT);
                break;
            case 3:
                show(HT);
                break;
            default:
                printf("[WARN] Please input a number between 1 and 3.\n\n");
                break;
        }
    }
    return 0;
}

void init(HashTable *HT)
{
    HT -> table_size = 0;
    int i;
    for(i = 0; i < MAX_TABLE_SZ; i++)
    {
        (HT -> HE)[i].key = -1;
        (HT -> HE)[i].value = -1;
    }
}
void show(HashTable HT)
{
    int i;
    printf("=========================\n");
    for(i = 0; i < (HT.table_size); i++)
    {
        printf("[%03d]%5d%5d\n", i, (HT.HE)[i].key, (HT.HE)[i].value);
    }
    printf("=========================\n\n");
}

void put(HashTable *HT)
{
    int key, value;
    printf("Input the key and the value of the entry: ");
    scanf("%d,%d", &key, &value);

    int h = key % (HT -> table_size);
    int tmp = h;
    while((HT -> HE)[tmp].key != -1)
    {
        tmp = (tmp + 1) % (HT -> table_size);
        if(tmp == h)
        {
            printf("[INFO] The space is not enough.\n\n");
            return;
        }
    }
    (HT -> HE)[tmp].key = key;
    (HT -> HE)[tmp].value = value;
    printf("[INFO] The entry %d has been added.\n\n", key);

}

void rm(HashTable *HT)
{
    int key;
    printf("Please input the key of the entry: ");
    scanf("%d", &key);

    int h = key % (HT -> table_size);
    int tmp = h;

    while((HT -> HE)[tmp].key != key)
    {
        tmp = (tmp + 1) % (HT -> table_size);
        if(tmp == h)
        {
            printf("[INFO] The key %d is not in the hash table.\n\n", key);
            return;
        }
    }
    (HT -> HE)[tmp].key = -1;
    (HT -> HE)[tmp].value = -1;
    printf("[INFO] The entry %d has been removed.\n\n", key);
}