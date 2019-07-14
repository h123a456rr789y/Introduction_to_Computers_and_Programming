#include<stdio.h>
int count(void);

int main(void)
{
    while(1)
    {
        printf ("Enter a binary number: ");
        if(count() % 3 == 0)
        {
            printf("Yeeee!\n\n");
        }
        else
        {
            printf("Boooo!\n\n");
        }
    }
    return 0;
}

int count(void)
{
    switch(getchar())
    {
        case '0':
            return 1 + count();
        case '1':
            return 0 + count();
        case '\n':
            return 0;
    }

}