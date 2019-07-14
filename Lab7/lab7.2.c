#include<stdio.h>
int count_zero(void);
int main(void)
{
while(1)
{
printf ("Enter a binary number: ");
if(count_zero() % 3 == 0)
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
int count_zero(void)
{
    char ch;
    ch=getchar();
    if(ch=='\n')
        return 0;
    else if(ch=='0')
       return count_zero()+1;
    else
        return count_zero()+0;
}
