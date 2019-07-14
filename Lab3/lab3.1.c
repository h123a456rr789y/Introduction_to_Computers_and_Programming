#include<stdio.h>

int main(void)
{
    /*int a,b,c,d,e,f;

    printf("Please enter the total seconds.\n");
    scanf("%d", &a);
    b=a/60/60/24/7;
    c=(a%604800)/86400;
    d=(a%86400)/3600;
    e=a/60%60;
    f=a%60;

    printf("Total seconds:%d\n",a);
    printf("Equal to %d week %d day %d hour %d minute %d second\n",b,c,d,e,f);
    return 0;*/
    int s,cnt;
    int span[]={60,60,24,7};
    int time[5];

    printf("Please enter the total seconds.\n");
    scanf("%d",&s);
    printf("Total seconds:%d\n",s);
    for(cnt=0;cnt<4;cnt++){
        time[cnt]=s%span[cnt];
        s/=span[cnt];
    }
    time[4]=s;

    char* timeName[]={"week","day","hour","minute","second"};

    printf("Equal to");
    for(cnt=0;cnt<5;cnt++)
        printf(" %d %s",time[4-cnt],timeName[cnt]);
    printf("\n");

    return 0;
}
