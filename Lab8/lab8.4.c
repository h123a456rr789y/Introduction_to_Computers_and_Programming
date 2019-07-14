#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a[5];
int stack=0;

void push(int n){
	if(stack==5)
		printf("The stack is already full\n");
	else{
		a[stack]=n;
		printf("%d is pushed.\n",n);
		stack++;
	}
}
void pop(int a[]){
	if(stack==0)
		printf("The stack is empty.\n");
	else{
		printf("%d is popped.\n",a[stack-1]);
		stack--;
	}
}
void show(int a[]){
	int i;
	if(stack==0){
		printf("The stack is empty.");
	}
	for(i=0;i<stack;i++){
		printf("%d ",a[i]);
	}
}
 
 
int main(void){
	while(1){	
		char check[20]={0},ch;
		int num,i=0;
		while((ch=getchar())!='\n'){
			if(isdigit(ch)){
				ungetc(ch,stdin);
				scanf("%d",&num);
			}
			else
				check[i++]=ch;
		}
		check[i]='\0';
		if(strcmp(check,"push() ")==0)
			push(num);
		else if(strcmp(check,"pop")==0)
			pop(a);
		else if(strcmp(check,"show")==0){
			show(a);
		}
		else
			printf("It's an illegal operation.\n");
		printf("\n");
	}
	return 0;
}
