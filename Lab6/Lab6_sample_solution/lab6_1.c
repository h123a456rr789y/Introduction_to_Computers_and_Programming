#include<stdio.h>

int main(void)
{
    int n, i;
    int arr[100];
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\n");
    int head = 0, tail = n-1;
    int count = 0;
    for(i = head; i <= tail; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    while(head != tail)
    {
        if(count%2 == 0)
        {
            arr[tail] += arr[head];
            head++;
            for(i = tail; i >= head; i--)
            {
                printf("%d ",arr[i]);
            }
            printf("\n");
        }
        else
        {
            arr[head] += arr[tail];
            tail--;
            for(i= head; i<= tail; i++)
            {
                printf("%d ",arr[i]);
            }
            printf("\n");
        }
        count++;
    }
    return 0;
}
