#include<stdio.h>
int main(void)
{
    while(1)
	{
	   int i, j, term;
	   int n;
	   float sum;
	   sum = 1.0;
	   printf("Input a Number: ");
	   scanf("%d", &n);

	   for(i=1; i<=n; i++)
	   {
	       term = 1;
	       for(j=1; j<=i; j++)
	       {
	           term *= j;
	       }
	       sum += (float)1/term;
		}
		printf("Answer: %f\n\n", sum);

	}
    return 0;
}
