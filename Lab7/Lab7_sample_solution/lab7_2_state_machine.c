#include<stdio.h>
void x3(void);
void x3_1(void);
void x3_2(void);

int main(void)
{
    while(1)
    {
        printf ("Enter a binary number: ");
        x3();
    }
    return 0;
}
// x3 represents a state that current # of zero is multiple of 3
void x3(void)
{
    switch (getchar())
    {
        case '0':
            x3_1();
            return;
        case '1':
            x3();
            return;
        case '\n':
            printf ("Yeeee!\n\n");
            return;
    }
}
// x3_1 represents a state that current # of zero is 3n+1
void x3_1(void) {
    switch (getchar())
    {
        case '0':
            x3_2();
            return;
        case '1':
            x3_1();
            return;
        case '\n':
            printf ("Boooo!\n\n");
            return;
    }
}
// x3_1 represents a state that current # of zero is 3n+2
void x3_2(void)
{
    switch (getchar())
    {
        case '0':
            x3();
            return;
        case '1':
            x3_2();
            return;
        case '\n':
            printf ("Boooo!\n\n");
            return;
    }
}
