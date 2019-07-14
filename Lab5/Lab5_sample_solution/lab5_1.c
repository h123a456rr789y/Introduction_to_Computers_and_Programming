#include<stdio.h>
int main(){
    int n,result,a1,a2,i;
    while(1){
        printf("After how many months:");
        scanf("%d",&n);
        if(n<0) printf("Error\n");
        else{
            a1=1,a2=2;
            if(n==0) result=a1;
            else if(n==1) result=a2;
            else{
                for(i=1;i<n;i++){
                    result=a1+a2;
                    a1=a2;
                    a2=result;
                }
            }
            printf("There are %d baby rabbit \n",2*(result-a1));
            printf("Total:%d rabbit \n",2*result);
            }
        printf("\n");
    }
    return 0;
}
