#include<stdio.h>
void reverse(int a[],int n)
{
    int i,j;
    for (i=1;i<n;i++)
        for (j=0;j<i;j++)
            if (a[j]>=a[i]) a[j]++;
}

void nhp(int a[],int n)
{
    int i;
    for (i=n-1;i>0;i--){
        if (a[i-1]<a[i]) break;
    }
    if (i>0) {
        int j=n-1;
        while (a[j]<=a[i-1]) j--;
        int z=a[i-1];
        a[i-1]=a[j];
        a[j]=z;
        j=n-1;
        while (i<j){
            z=a[i];
            a[i]=a[j];
            a[j]=z;
            i++;
            j--;
        }
    }
}

int main(){
    printf("Please input n:");
    int n,m;
    scanf("%d",&n);
    int a[n];
    printf("Please input elements of the inversion vector:\n");
    int i=0;
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("\n");
    int len=n;
    reverse(&a,len);

    printf("Array a is:");
    for(i=0;i<len;i++){
        if(i==0){
            printf("%d",a[i]);
        }
        else{
            printf(",%d",a[i]);
        }
    }
    printf("\n\n");
    printf("Please input m:");
    scanf("%d",&m);
    printf("The next %d higher permutations of Array a are:\n",m);
    int k=0;
    while(k<m){
        int tmp[len];
        int i=0;
        for(i=0;i<len;i++){
            tmp[i]=a[i];
        }
        nhp(&a,len);

        for(i=0;i<len;i++){
            if(i==0){
                printf("%d",a[i]);
            }
            else{
                printf(",%d",a[i]);
            }
        }
        printf("\n");
        k++;
    }
}
