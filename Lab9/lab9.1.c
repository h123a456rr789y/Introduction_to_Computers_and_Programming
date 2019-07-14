#include<stdio.h>
#define MAX_TABLE_SZ 10
typedef struct {
	int key;
	int value;
}HashEntry;
typedef struct {
	int table_size;
	HashEntry HE[MAX_TABLE_SZ];
}HashTable;

int main(void) {
	int size,oper,i,pos;
	int key, value;
	HashTable table;
	printf("Input the size of the hash table\n-");
	scanf("%d",&size);
	table.table_size=size;
	for(i=0;i<size;i++){
		table.HE[i].key=-1;
		table.HE[i].value=-1;
	}
	while(1){
		printf("Input the operation:(1)Add an entry; (2)Remove an entry by key;(3) show\n-");
		scanf("%d",&oper);
		switch(oper){
			case 1:
				printf("Input the key and the value of the entry:");
				scanf("%d,%d",&key,&value);
				pos=key%size;
				int n=1;
				while(table.HE[pos].key!=-1){
					pos=(key+n)%size;
					n++;
                    if(n==size+1){
                        printf("[INFO] The space is not enough.\n");
                        break;
                    }
				}
				if(n==size+1) break;
				table.HE[pos].key=key;
				table.HE[pos].value=value;
                printf("[INFO] The entry %d has been added.\n",key);
				break;
			case 2:
				printf("Please input the key of the entry:");
				scanf("%d",&key);
				for(i=0;i<size;i++){
					if(table.HE[i].key==key)
                        pos=i;
						break;
				}
				table.HE[i].key=-1;
				table.HE[i].value=-1;
				printf("[INFO] The entry %d has been removed.\n",pos);
				break;
			case 3:
				printf("===================\n");
					for(i=0;i<size;i++){
						printf("[%03d]",i);
						printf("%4d%4d\n",table.HE[i].key,table.HE[i].value);
					}
				printf("===================\n");
				break;
		}
	}
	return 0;
}
