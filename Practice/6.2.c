#include<stdio.h>
#include<stdlib.h>

int main(void){
    int i;
    char ch;
    while(1){
        ch=getchar();
        int a[10]={0};
        while(ch!='\n'){
            switch(ch){
            case '0':
                a[0]++;
                break;
            case '1':
                a[1]++;
                break;
            case '2':
                a[2]++;
                break;
            case '3':
                a[3]++;
                break;
            case '4':
                a[4]++;
                break;
            case '5':
                a[5]++;
                break;
            case '6':
                a[6]++;
                break;
            case '7':
                a[7]++;
                break;
            case '8':
                a[8]++;
                break;
            case '9':
                a[9]++;
                break;
            default:
                break;
            }
            ch=getchar();
        }
        printf("Digit:\t\t0 1 2 3 4 5 6 7 8 9\n");
        printf("Occurrences:\t");
        for(i=0;i<10;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
        printf("Appear Most:\t");
        int max=a[0],most;
        for(i=1;i<10;i++){
            if(a[i]>max){
                max=a[i];
                most=i;
            }
        }
        printf("%d\n",most);
        printf("\n");
    }
    return 0;
}
