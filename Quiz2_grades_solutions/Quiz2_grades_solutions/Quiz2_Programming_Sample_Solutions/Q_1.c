#include <string.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct node
{
    char data[101];
    struct node * next;
} Node;
/**************************************************************************
    If you are not familiar with the operation of linked list insertion,
    all you have to know is there are 4 situations in insertion:
    (1) Insert to an empty list,
    (2) Insert to the first of the list,
    (3) Insert to the middle of the list,
    (4) Insert to the last of the list.
***************************************************************************/
Node *insert_node(Node *list, char element[]);

int main(void)
{
    Node *first = NULL,*p;
    int n, member;
    char str[101];

    while(1)
    {
        printf("Enter a string : ");
        scanf("%s", &str);
        first = insert_node(first, str);

        printf("The list content: ");
        for(p = first; p!= NULL; p = p->next)
        {
            if(p!=first) printf(" -> ");
            printf("%s", p->data);
        }
        printf("\n\n");

    }
    return 0;
}

Node *insert_node(Node *list, char element[])
{
    Node *new_node = malloc(sizeof(Node));
    strcpy(new_node->data, element);
    new_node -> next = NULL;

    Node *prev, *cur;
    if(list == NULL)                        // (1) Insert to an empty list
    {
        new_node -> next = NULL;
        return new_node;
    }
    else
    {
        cur = list;
        if(strcmp(element,cur -> data) < 0) // (2) Insert to the first of the list
        {
            new_node -> next = cur;
            return new_node;
        }
        else
        {
            while(cur -> next != NULL)      // (3) Insert to the middle of the list
            {
                prev = cur;
                cur = cur -> next;
                if(strcmp(element, cur -> data) < 0)
                {
                    prev -> next = new_node;
                    new_node -> next = cur;
                    return list;
                }
            }
            cur -> next = new_node;         // (4) Insert to the last of the list
            return list;
        }
    }
}

