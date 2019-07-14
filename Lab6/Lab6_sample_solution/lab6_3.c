#include<stdio.h>

int main(){
    int n,i,dem;
    while(1){
        printf("Please input n:");
        scanf("%d",&n);
        printf("Please input the decimal number:");
        scanf("%d",&dem);
        int a[n],c=1,over=1;
        for(i=0;i<n;i++)
            a[i]=0;
        for(i=0;i<n-1;i++){
            over*=2;
        }

        if(dem>over-1 || dem<-over){
            printf("Overflow\n");
        }
        else{
            if(dem>0){
                for(i=n-1;i>=0;i--){
                    a[i]=dem%2;
                    dem=dem/2;
                }
            }
            if(dem<0){
                dem=-dem;
                for(i=n-1;i>=0;i--){
                    a[i]=dem%2;
                    dem=dem/2;
                }
                for(i=n-1;i>=0;i--){
                    a[i]=(a[i]+1)%2;
                }
                for(i=n-1;i>=0;i--){
                    if((a[i]+c)>1){
                        a[i]=0;
                        c=1;
                    }
                    else{
                        a[i]+=c;
                        c=0;
                    }
                }
            }
            for(i=0;i<n;i++)
                printf("%d",a[i]);
            printf("\n");
        }
        printf("\n");
    }
}
