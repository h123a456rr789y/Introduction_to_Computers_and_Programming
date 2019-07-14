#include<stdio.h>
#include<string.h>
int stk[5];
int top = -1;
int isIllegal(char str[])
{
    int left_count = 0, right_count = 0, pos1, pos2, i = 0;
    while(str[i] != '\0')
    {
        if(str[i] == '(')
        {
            left_count++;
        }
        else if(str[i] == ')')
        {
            right_count++;
        }
        i++;
    }
    // type 1: left and right parenthesis are not in a pair
    if(left_count != right_count || left_count > 1 || right_count > 1)
    {
        return 1;
    }

    i = 0;
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
    // type 2: position of parenthesis is opposite
    // type 3: there are something behind ')'
    if(pos2 < pos1 ||  pos2 != (strlen(str)-1))
    {
        return 1;
    }

    i = 0;
    while(str[i] != '\0')
    {
        if(i > pos1 && str[i] != ')' && (str[i] < '0' || str[i] > '9') )
        {
            break;
        }
        i++;
    }
    // type 4: there is some other symbols in parenthesis
    if(i < strlen(str))
    {
        return 1;
    }
    return 0;
}
void push_stack(char str[])
{
    if(isIllegal(str))
    {
        printf("It is an illegal operation.\n");
    }
    else
    {
        int pos1, pos2, i = 0;
        int sum = 0;
        if(top >= 4)
        {
            printf("The stack is already full.\n");
        }
        else
        {
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
            //push
            printf("%d is pushed.\n", sum);
            stk[++top] = sum;
        }
    }
}
void pop_stack()
{
    if(top == -1)
    {
        printf("The stack is already empty.\n");
    }
    else
    {
        printf("%d is popped.\n", stk[top--]);
    }
}
void print_stack()
{
    int i;
    if(top == -1)
    {
        printf("The stack is empty.");
    }
    else
    {
        for(i = 0; i <= top; i++)
        {
            printf("%d ", stk[i]);
        }
    }
    printf("\n");
}

int main(void)
{
    while(1)
    {
        char str[100];
        printf("- ");
        gets(str);

        // pre-filter inputs like: push, 123push(2), push)
        if(strstr(str, "push(") && str[4] == '(')
        {
            push_stack(str);
        }
        else if(strstr(str, "pop") && strlen(str) == 3)
        {
            pop_stack();
        }
        else if(strstr(str, "show") && strlen(str) == 4)
        {
            print_stack();
        }
        else
        {
            printf("It is an illegal operation.\n");
        }
    }

    return 0;
}
