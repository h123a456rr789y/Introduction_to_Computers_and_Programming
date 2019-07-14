#include<stdio.h>
#include<stdlib.h>

int main(void){
	while(1){
	char str1[100],str2[100];
	int check[100]={0};
	int temp=0,samenum=0;
	int i,j;
	int strlen1=0,strlen2=0;
		gets(str1);
		gets(str2);
		while(str1[strlen1]!='\0'){
			strlen1++;
		}
		while(str2[strlen2]!='\0'){
			strlen2++;
		}
		//printf("%d %d",strlen1,strlen2);
		for(i=0;i<strlen1;i++){
			for(j=0;j<strlen2;j++){
				if(str1[i]==str2[j]){
					samenum++;
					check[j]=1;
				}
			}
		}
		for(i=0;i<100;i++){
			if(check[i]==1)
				temp++;
		}
		//printf("%d\n",temp);
		//printf("%d\n",samenum);
		if(strlen1==strlen2&&samenum==strlen1)
			printf("String1 is a Continous substracting of String2\n");
		else{
			if(temp==strlen1)
				printf("String1 is a Non-continous substracting of String2\n");
			else
				printf("String1 is not a Continous substracting of String2\n");
		}
	}
	return 0;
} 
