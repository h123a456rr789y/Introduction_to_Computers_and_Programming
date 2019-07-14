#include <stdlib.h>
#include <stdio.h>
typedef struct node
{
    int value;
    struct node * next;
} Node;

Node *add_to_first(Node *list, int element);
Node *add_to_last(Node *list, int element);

int main(void)
{
    Node *first = NULL, *p;
    int n, member;

    while(1)
    {
        printf("(0) Quit  (1) Add-to-First  (2) Add-to-Last\n");
        printf("Enter the number of the function : ");
        scanf("%d", &n);
        if (n==0) break;
        switch(n)
        {
            case 1:
                printf("Enter the element to be added: ");
                scanf("%d", &member);
                first = add_to_first(first, member);
                break;
            case 2:
                printf("Enter the element to be added: ");
                scanf("%d", &member);
                first = add_to_last(first, member);
                break;
            default:
                continue;
        }

        printf("The list content: ");
        if(first==NULL)
        {
            printf("(Empty)\n\n");
            continue;
        }
        for(p = first; p!= NULL; p = p->next)
        {
            if(p!=first) printf(" -> ");
            printf("%d", p->value);
        }
        printf("\n\n");

    }
    return 0;
}

Node *add_to_first(Node *list, int element)
{
    Node *new_Node = (Node *)malloc(sizeof(Node));
    new_Node->value = element;
    new_Node->next = list;
    return new_Node;
}

Node *add_to_last(Node *list, int element)
{
    Node *p = list;
    Node *new_Node = (Node *)malloc(sizeof(Node));
    new_Node->value = element;
    new_Node->next = NULL;

    // The list is empty
    if(!list)
    {
        list = new_Node;
        return list;
    }
    for( ; p->next!=NULL; p=p->next);
    p->next = new_Node;
    return list;
}
