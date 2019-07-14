#include<stdio.h>
int main(void)
{
    int freq[10] = {0};
    int digit, i, max = 0;;
    char ch;

    while((ch=getchar()) != '\n')
    {
        digit = ch - '0';
        freq[digit]++;
    }


    printf("Digit:\t\t");
    for(i = 0; i < 10; i++)
    {
        printf("%2d", i);
    }

    printf("\nOccurrences:\t");
    for(i = 0; i < 10; i++)
    {
        printf("%2d", freq[i]);
    }


    printf("\nAppear Most:\t");
    for(i = 0; i < 10; i++)
    {
        if(freq[i] > freq[max])
        {
            max = i;
        }
    }
    printf("%2d\n\n", max);
    return 0;
}
