#include<stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct
{
    int *stk;
    int top;
    int size;
} dynamicStack;

void print_stack(dynamicStack* mystack);
void push_stack(char str[], dynamicStack* mystack);
void pop_stack(dynamicStack* mystack);


int main(void)
{
    //initialize
    dynamicStack mystack;
    mystack.size = 1;
    mystack.top = -1;
    mystack.stk = (int *)calloc(2, sizeof(int));

    while(1)
    {
        char str[100];
        printf("- ");
        gets(str);
        if(strstr(str, "push("))
        {
            push_stack(str, &mystack);
        }
        else if(strstr(str, "pop") && strlen(str) == 3)
        {
            pop_stack(&mystack);
        }
        else if(!strcmp(str, "-1"))
        {
            break;
        }
    }
    free(mystack.stk);
    return 0;
}

void print_stack(dynamicStack* mystack)
{
    printf("The size of the stack is %d\n", mystack->size);
    int i;
    for(i = 0; i<= mystack->top;i++)
    {
        printf("%3d", (mystack->stk)[i]);
    }
    printf("\n\n");
}

void push_stack(char str[], dynamicStack* mystack)
{
    int pos1, pos2, i=0, sum =0;
    // Find position of parenthesis
    while(str[i] != '\0')
    {
        if(str[i] == '(')
        {
            pos1 = i;
        }
        else if(str[i] == ')')
        {
            pos2 = i;
        }
        i++;
    }
    // Calculate the value of pushing value
    for(i = pos1 + 1; i < pos2; i++)
    {
        sum = (sum * 10) + (str[i] - '0');
    }

    // Need to dynamic expand the stack
    if(mystack->top + 1 >= mystack->size )
    {
        (mystack->size) *= 2;
        (mystack->stk) = (int *)realloc((mystack->stk), (mystack->size)*sizeof(int));
    }

    (mystack->stk)[++(mystack->top)] = sum;
    print_stack(mystack);
}

void pop_stack(dynamicStack* mystack)
{
    if(mystack->top > -1)
    {
        if(mystack->top  <= mystack->size / 2)
        {
            if(mystack->size > 1)
            {
                (mystack->size) /= 2;
            }
            (mystack->stk) = (int *)realloc((mystack->stk), (mystack->size)*sizeof(int));
        }
        (mystack->top)-- ;
    }
    print_stack(mystack);
}
