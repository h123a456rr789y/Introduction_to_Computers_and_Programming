#include <stdlib.h>
#include <stdio.h>
typedef struct node
{
    int value;
    struct node * next;
} Node;

Node *push(Node *list, int element);
Node *pop(Node *list);
void free_stack(Node *list);


int main(void)
{
    Node *first = NULL, *p;
    int n, value;

    while(1)
    {
        printf("(1) Push  (2) Pop  (3) Exit\n");
        printf("Enter the number of the function : ");
        scanf("%d", &n);
        if (n==0) break;
        switch(n)
        {
            case 1:
                printf("Enter the value to be pushed: ");
                scanf("%d", &value);
                first = push(first, value);
                break;
            case 2:
                if(first != NULL)
                {
                    first = pop(first);
                }
                break;
            case 3:
                free_stack(first);
                printf("Bye!\n\n");
                return 0;
            default:
                continue;
        }

        printf("The list content: ");
        if(first==NULL)
        {
            printf("NULL\n\n");
            continue;
        }
        for(p = first; p!= NULL; p = p->next)
        {
            if(p!=first) printf(" -> ");
            printf("%d", p->value);
        }
        printf(" -> NULL\n\n");
    }
    return 0;
}
void free_stack(Node *list)
{
    Node *tmp;
    while(list != NULL)
    {
        tmp = list;
        list = list->next;
        free(tmp);
    }

}
Node *pop(Node *list)
{
    Node *new_first = list -> next;
    free(list);
    return new_first;
}
Node *push(Node *list, int element)
{
    Node *new_Node = malloc(sizeof(Node));
    new_Node->value = element;
    new_Node->next = list;
    return new_Node;
}
