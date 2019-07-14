#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(void){
    int i;
    char ch;

    ch=getchar();

    int cnt[10]={0};

    printf("Digit:\t\t0 1 2 3 4 5 6 7 8 9\n");
    printf("Occurrences:\t");
    while(ch!='\n'){
        switch(ch){
        case'1':cnt[1]++;
                break;
        case'2':cnt[2]++;
                break;
        case'3':cnt[3]++;
                break;
        case'4':cnt[4]++;
                break;
        case'5':cnt[5]++;
                break;
        case'6':cnt[6]++;
                break;
        case'7':cnt[7]++;
                break;
        case'8':cnt[8]++;
                break;
        case'9':cnt[9]++;
                break;
        case'0':cnt[0]++;
                break;
        }
        ch=getchar();
    }
    for(i=0;i<10;i++){
            printf("%d ",cnt[i]);
    }

    int max=cnt[1],x;
        for(i=0;i<10;i++){
            if(cnt[i]>max){
                max=cnt[i];
                x=i;
            }
        }

    printf("\nAppear most:\t");
    printf("%d",x);


    return 0;
}
