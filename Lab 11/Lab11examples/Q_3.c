#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
    struct node *prv;
    int data;
    int i;
    struct node *next;
}node;
typedef struct nodes{
    node *head;
    node *nodei;
}nodes;

void minus(node *head);
nodes insert_left(nodes nodes);
nodes insert_right(nodes nodes);
nodes move_left(nodes nodes);
nodes move_right(nodes nodes);
nodes remove_node(nodes nodes);
void print_list(nodes nodes);
int main()
{
    int c;
    nodes nodes;
    nodes.head=NULL;
    nodes.nodei=NULL;
    printf("Functions: (1)insert_left (2)insert_right (3)move_left\n           (4)move_right  (5)remove_node  (6)print_list\n");
    while(1)
    {
        printf("Select function: ");
        scanf("%d",&c);
        if(c==1)
            nodes=insert_left(nodes);
        else if(c==2)
            nodes=insert_right(nodes);
        else if(c==3)
            nodes=move_left(nodes);
        else if(c==4)
            nodes=move_right(nodes);
        else if(c==5)
            nodes=remove_node(nodes);
        else if(c==6)
            print_list(nodes);
    }
}
void minus(node *head)
{
    while(head!=NULL)
    {
        head->i--;
        head=head->next;
    }

}
nodes remove_node(nodes nodes)
{
    if(nodes.head==NULL)
        printf("Cannot remove node from empty list\n\n");
    else
    {
        if(nodes.head==nodes.nodei)
            nodes.head=nodes.nodei->next;
        else
            nodes.nodei->prv->next=nodes.nodei->next;
        if(nodes.nodei->next!=NULL)
        {
            minus(nodes.nodei);
            nodes.nodei->next->prv=nodes.nodei->prv;
            nodes.nodei=nodes.nodei->next;
        }
        else
            nodes.nodei=nodes.nodei->prv;
        if(nodes.nodei!=NULL)
            printf("Interator:Node%d Value:%d\n\n",nodes.nodei->i,nodes.nodei->data);
        else
            nodes.head=nodes.nodei;

    }
    
    return nodes;
}
nodes move_right(nodes nodes)
{
    if(nodes.head==NULL||nodes.nodei==NULL)
        printf("Cannot move to the left node\n\n");
    else
    {
        if(nodes.nodei->next==NULL)
            printf("Cannot move to the right node\n\n");
        else
            nodes.nodei=nodes.nodei->next;
        printf("Interator:Node%d Value:%d\n\n",nodes.nodei->i,nodes.nodei->data);
    }
    return nodes;
}

nodes move_left(nodes nodes)
{
    if(nodes.head==NULL||nodes.nodei==NULL)
        printf("Cannot move to the left node\n\n");
    else
    {
        if(nodes.nodei->next==NULL)
            printf("Cannot move to the left node\n\n");
        else
            nodes.nodei=nodes.nodei->prv;
        printf("Interator:Node%d Value:%d\n\n",nodes.nodei->i,nodes.nodei->data);
    }
    
    return nodes;
}

nodes insert_right(nodes nodes)
{
    node *cur=NULL;
    cur=(node*)malloc(sizeof(node));
    cur->next=NULL;
    cur->prv=NULL;
    cur->data=-1;
    cur->i=-1;
    printf("Insert the value: ");
    scanf("%d",&cur->data);
    if(nodes.head==NULL)
    {
        cur->i=0;
        nodes.head=cur;
        nodes.nodei=cur;
    }
    else
    {
        cur->i=nodes.nodei->i+1;
        if(nodes.nodei->next!=NULL)
            nodes.nodei->next->i++;
        cur->next=nodes.nodei->next;
        if(cur->next!=NULL)
            cur->next->prv=cur;
        nodes.nodei->next=cur;
        cur->prv=nodes.nodei;
    }
    printf("Interator:Node%d Value:%d\n\n",nodes.nodei->i,nodes.nodei->data);
    return nodes;
}

void print_list(nodes nodes)
{
    if(nodes.head==NULL)
        printf("Empty list\n\n");
    else
    {
        while(nodes.head!=NULL)
        {
            printf("%d", nodes.head->data);
            nodes.head=nodes.head->next;
            if(nodes.head!=NULL)
                printf(" -> ");
        }
        printf("\nInterator:Node%d Value:%d",nodes.nodei->i,nodes.nodei->data);
        printf("\n\n");
    }
    
}

nodes insert_left(nodes nodes)
{
    node *cur=NULL;
    cur=(node*)malloc(sizeof(node));
    cur->next=NULL;
    cur->prv=NULL;
    cur->data=-1;
    cur->i=-1;
    printf("Insert the value: ");
    scanf("%d",&cur->data);
    if(nodes.head==NULL)
    {
        cur->i=0;
        nodes.head=cur;
        nodes.nodei=cur;
    }
    else
    {
        nodes.nodei->i++;
        cur->i=nodes.nodei->i-1;
        cur->prv=nodes.nodei->prv;
        if(cur->prv!=NULL)
            cur->prv->next=cur;
        else
            nodes.head=cur;
        nodes.nodei->prv=cur;
        cur->next=nodes.nodei;
        
    }
    printf("Interator:Node%d Value:%d\n\n",nodes.nodei->i,nodes.nodei->data);
    return nodes;
}
