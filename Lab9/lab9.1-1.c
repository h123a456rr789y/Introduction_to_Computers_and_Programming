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

int main(void){
	int size,opt,pos;
	int key,value,i;
	HashTable Table;
	printf("Input the size of the hash table\n- ");
	scanf("%d",&size);
	Table.table_size=size;
	for(i=0;i<size;i++){
		Table.HE[i].key=-1;
		Table.HE[i].value=-1;
	}
	while(1){

	printf("Input the operation:(1)Add an entry;(2)Remove an entry by key;(3)Show\n- ");
	scanf("%d",&opt);
		switch(opt){
			case 1:{
				printf("Input the key and the value of the entry:");
				scanf("%d,%d",&key,&value);
				pos=key%size;
				Table.HE[pos].key=key;
				Table.HE[pos].value=value;
				while(Table.HE[pos].key!=-1){
					int n=1;
					pos=(key+n)%size;
					n++;
					if(n==size){
						printf("[INFO] The space is not enough\n");
						break;
					}
				}
				printf("[INFO] The entry %d has been added.\n",key);
				break;
			}
			case 2:{
					printf("Pleasse input the key of the entry:");
					scanf("%d",&key);
					for(i=0;i<size;i++){
						if(Table.HE[size].key==key)
							break;
						pos=i;
						Table.HE[i].key=-1;
						Table.HE[i].value=-1;
					printf("[INFO] The entry %d has been removed.\n",key);
					}
				break;
			}
			case 3:{
				printf("======================\n");
				for(i=0;i<size;i++){
					printf("[%03d]\t%d\t%d",i,Table.HE[i].key,Table.HE[i].value);
					printf("\n");
				}
				printf("\n======================\n");
				break;
			}
			default:
				break;
		}
	}
	return 0;

}
