#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int gcd(int i, int j);
int decimal_to_binary(int i);
int sum_of_digit(int i, int j);
void bubble_sort(double arr[], int n);

int main(void)
{
    double arr[20];
    int k, n = 0;

    while(1)
    {
        int i, j, a, b, c;
        printf("Input 2 numbers: ");
        scanf("%d,%d", &i, &j);
        if(i == 0 || j == 0)    break;

        a = gcd(i, j);
        printf("(1) GCD of %d and %d is %d\n", i, j, a);

        printf("(2) Binary number of %d is ", a);
        b = decimal_to_binary(a);
        printf("and there are %d zero in it\n", b);

        c = sum_of_digit(i, j);

        arr[n++] = (double) a * (b + 1) / (c + 1);
    }

    bubble_sort(arr, n);

    return 0;
}


int gcd(int i, int j)
{
    if(j == 0)
    {
        return i;
    }
    else
    {
        return gcd(j, i%j);
    }

}


int decimal_to_binary(int i)
{
    int count = 0, n = 0, j, binary[50];

    while(i > 0)
    {
        binary[n++] = i % 2;
        if(i % 2 == 0)
        {
            count++;
        }
        i /= 2;
    }
    for(j = n-1; j >= 0; j--)
    {
        printf("%d", binary[j]);
    }
    printf(", ");
    return count;
}


int sum_of_digit(int i, int j)
{
    char str[100], tmp[100];
    int sum, k;
    sprintf(str,"%d%d", i, j);
    strcpy(tmp, str);

    while(strlen(str) > 1)
    {
        sum = 0;
        for(k = 0; k < strlen(str); k++)
        {
            sum += (str[k] - '0');
        }
        sprintf(str, "%d", sum);
    }
    printf("(3) The sum of digits %s is %d\n\n", tmp, sum);
    return sum;

}


void bubble_sort(double arr[], int n)
{
    int i, j;
    for(i = n - 1; i > 0; i--)
    {
        for( j = 0; j < i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                double tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }

    printf("(4) The smallest to the biggest: ");
    printf("%08.3lf", arr[0]);
    for(i = 1; i < n; i++)
    {
        printf(" -> %08.3lf", arr[i]);
    }
    printf("\n");
}
