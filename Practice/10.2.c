#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
    int value;
    struct node *next;
}Node;
Node *first;
void AddToFirst(int n){
    Node *p;
    Node *new_node=malloc(sizeof(Node));
    p=first;
    new_node->value=n;
    new_node->next=p;
    first=new_node;
}
void AddToLast(int ele){
    Node *new_node=malloc(sizeof(Node));
    new_node->next=NULL;
    new_node->value=ele;
    Node *p=first;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=new_node;
}
void Print(){
    Node *p;
    for(p=first;p!=NULL;p=p->next){
        if(p!=first){
            printf(" -> ");
        }
        printf("%d",p->value);
    }
}


int main(void){
    int func,ele;
    while(1){
        printf("(0) Quit (1)Add-to-First (2) Add-to-Last\n");
        printf("Enter the number of the function:");
        scanf("%d",&func);
        switch(func){
        case 0:
            return 0;
            break;
        case 1:
            printf("Enter the element to be added:");
            scanf("%d",&ele);
            AddToFirst(ele);
            printf("The list content:");
            Print();
            break;
        case 2:
            printf("Enter the element to be added:");
            scanf("%d",&ele);
            AddToLast(ele);
            printf("The list content:");
            Print();
            break;
        default:
            break;
        }
        printf("\n");
    }

    return 0;
}
