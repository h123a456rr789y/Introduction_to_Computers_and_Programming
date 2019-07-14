#include <stdio.h>
#include <stdlib.h>



char txt[7]={};
int t[14]={0},cal[15],zero=0;                      //cal:calculate    //zero:numbers of =0
int num[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
FILE *fp;



void change(int n,int amo,int i){
    int j;
    for(t[i]=0;t[i]<3;t[i]++){                      //0=='+',1=='-',2=='_'
        if(t[i]==2){
            if(num[i+1]<=9) cal[amo]=cal[amo]*10+num[i+1];
            else    cal[amo]=cal[amo]*100+num[i+1];
        }
        else{
            cal[++amo]=num[i+1];
        }
        if(i==(n-2)){
            int k=1;
            int sum=cal[0];
            for(j=0;j<(n-1);j++){
                if(t[j]==0){
                    sum+=cal[k];
                    k++;
                }
                else if(t[j]==1){
                    sum-=cal[k];
                    k++;
                }
            }
            if(sum==0){
                zero++;
                fp=fopen(txt,"a+");
                int i;
                for(i=0;i<(n-1);i++){
                    fprintf(fp,"%d",num[i]);
                    if(t[i]==0) fprintf(fp,"+");
                    if(t[i]==1) fprintf(fp,"-");
                    if(t[i]==2) fprintf(fp," ");
                }
                fprintf(fp,"%d",num[n-1]);
                fprintf(fp,"\n");
                fclose(fp);
            }
        }
        i++;
        if(i<(n-1))    change(n,amo,i);              //new for loop in for loop
        i--;
        amo--;
    }
}






int main()
{
    while(1){
        int n,i,amo=0;                    //amo:array numbers of cal[]
        printf("Input a number: ");
        scanf("%d",&n);


                                            //file name
        if(n>=3&&n<=9){
            txt[0]=n+'0';
            txt[1]='.';
            txt[2]='t';
            txt[3]='x';
            txt[4]='t';
        }
        else{
            txt[0]='1';
            txt[1]=n-10+'0';
            txt[2]='.';
            txt[3]='t';
            txt[4]='x';
            txt[5]='t';
        }


        i=0;
        cal[0]=1;
        change(n,amo,i);

        fp=fopen(txt,"a+");
        fprintf(fp,"There are %d equations that equal to 0",zero);
        printf("There are %d equations that equal to 0\n\n",zero);

        zero=0;
        txt[5]=NULL;
        fclose(fp);
    }
}

