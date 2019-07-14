#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int value;
    struct node *next;
}Node;

Node *first;

void Print_List(Node *first){
    Node *p;
    printf("The list content:");
    for(p=first;p!=NULL;p=p->next){
        if(p!=first){
            printf("-> ");
        }
        printf("%d ",p->value);
    }

}
void Add_To_First(int ele){
    Node *new_node=malloc(sizeof(Node));
    new_node->value=ele;
    new_node->next=first;
    first=new_node;
}
void Add_To_Last(int ele){
    Node *p=first;
    Node *new_node=malloc(sizeof(Node));
    new_node->next=NULL;
    new_node->value=ele;
    if(p==NULL){
        first=new_node;
    }
    else{
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=new_node;
    }
}

int main(){
    int func,n;
    first=NULL;
    while(1){
        printf("(0) Quit (1) Add-to-First (2) Add-to-Last\n");
        printf("Enter the number of the function:");
        scanf("%d",&func);
        switch(func){
            case 1:{
                printf("Enter the number to be added:");
                scanf("%d",&n);
                Add_To_First(n);
                Print_List(first);
                break;
            }
            case 0:{
                return 0;
                break;
            }
            case 2:{
                printf("Enter the element to be added:");
                scanf("%d",&n);
                Add_To_Last(n);
                Print_List(first);
                break;
            }
            default:break;
        }
        printf("\n");
    }
    return 0;
}
