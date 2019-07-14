#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int value;
	struct node *next;
} Node;

Node *AddToFirst(Node *first,int elem){
	Node *new_node;
	new_node=malloc(sizeof(Node));
	new_node->value=elem;
	new_node->next=first;
	
	return new_node;	
}
Node *AddToLast(Node *first,int elem){
	Node *p=first;
	Node *new_node=malloc(sizeof(Node));
	new_node->value=elem;
	new_node->next=NULL;
	
	if(!first){
		first=new_node;
		return first;
	}
	for(;p->next!=NULL;p=p->next);
		p->next=new_node;
		return first;
}


int main(void){
	Node *first=NULL, *p;
	
	
	int func,ele;
	while(1){	
		printf("(0)Quit (1) Add-to-First (2)Add-to-Last\n");
		printf("Enter the number of the function:");
		scanf("%d",&func);
		switch(func){
			case 1:
				printf("Enter the element to be added:");
				scanf("%d",&ele);
				first=AddToFirst(first,ele);
				break;
			case 2:
				printf("Enter the element to be added:");
				scanf("%d",&ele);
				first=AddToLast(first,ele);
				break;
			case 0:
				return 0;
				break;
			default:
				continue;
		}
		printf("The list content:");
		if(first==NULL){
			printf("Empty\n");
		}
		for(p=first;p!=NULL;p=p->next){
			if(p!=first){
				printf("->");
			}
			printf("%d",p->value);
		}
		printf("\n");
	}
	return 0;
}
