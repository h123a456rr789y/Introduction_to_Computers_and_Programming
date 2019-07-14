#include<stdio.h>
#include<stdlib.h>
#define MAX_INPUT 15
#define MIN_INPUT 3

int optr[15] = {0};
int count;
FILE *fout;

void generate_optr(int, int);
void check_sum(int);


int main(void)
{
    int n;
    printf("Input a number: ");
    while(scanf("%d",&n))
    {
        if(n < MIN_INPUT || n > MAX_INPUT)
        {
            printf("Wrong input. Please enter an input again.\n\n");
        }
        else
        {
            char filename[100];
            sprintf(filename, "%d.txt", n);
            fout = fopen(filename, "w");
            count = 0;
            generate_optr(n, 2);
            printf("There are %d equations that equal to 0\n\n", count);
            fprintf(fout, "There are %d equations that equal to 0\n\n", count);
            fclose(fout);
        }
        printf("Input a number: ");
    }
    return 0;
}

/************************************************************
   Generate operators for each digit.
   You can use only for-loop to generate,
   we demonstrate an alternative solution to solve it:
   recursion for each digit, iteration for each operator.
*************************************************************/
void generate_optr(int n, int current_digit)
{
    if(current_digit == n + 1)
    {
        check_sum(n);
    }
    else
    {
        int i;
        int next_digit = current_digit + 1;
        for(i = 0 ; i < 3 ; i++)
        {
            optr[current_digit] = i;
            generate_optr(n, next_digit);
        }
    }
}

/************************************************************
   When operator generation is done,
   Check the sum of equation to decide to print or not
*************************************************************/
void check_sum(int n)
{
    int i;
    int sum_queue[15] = {1};
    int rear = 0;

    for(i = 2 ; i <= n ; i++)
    {
        if(optr[i] == 0)
        {
            int shift = 10;
            if(i > 9)   shift = 100;

            int temp = i;
            if(sum_queue[rear] < 0) temp = 0 - i;

            sum_queue[rear] = sum_queue[rear] * shift + temp;
        }

        else if(optr[i] == 1)
        {
            sum_queue[++rear] = i;
        }

        else if(optr[i] == 2)
        {
            sum_queue[++rear] = 0 - i;
        }
    }

    int sum = 0;
    for(i = 0 ; i <= rear ; i++)
    {
        sum += sum_queue[i];
    }

    if(sum == 0)
    {
        count++;
        fprintf(fout, "1");
        for(i = 2 ; i <= n ; i++)
        {
            if(optr[i] == 0)        fprintf(fout, " ");
            else if(optr[i] == 1)   fprintf(fout, "+");
            else if(optr[i] == 2)   fprintf(fout, "-");
            fprintf(fout, "%d", i);
        }
        fprintf(fout, "\n");
    }
}
