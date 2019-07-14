#include<stdio.h>
#define size 10

void swap(int *p, int *q)
{
    int tmp = *p;
    *p = *q;
    *q = tmp;

    return;
}

int main()
{
    while(1)
    {
        int n, i, j;
        int arr[size];

        printf("Input the size: ");
        scanf("%d",&n);

        printf("Before sort: ");
        for(i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        // With size n, at least need (n-1) loops to let the "bubble" float up
        for(i = n - 1; i > 0; i--)
        {
            // In each loop, compare pair by pair. Be aware of boundary.
            for( j = 0; j < i; j++)
            {
                if(arr[j] > arr[j + 1])
                {
                    swap(arr + j, arr + j + 1);
                }
            }
        }

        printf("After sort: ");
        for(i=0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n\n");
    }

    return 0;
}
