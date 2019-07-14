#include<stdio.h>
#include<stdlib.h>

int main(void){
	char assign[10];
	int stack[100];
	char ch;
	int stacknum=0;
	int num,i,j,k=1;
    int size=1;
	while(1){
		printf("- ");
		i=0;
		while((ch=getchar())!='\n'){
			if(isdigit(ch)){
				ungetc(ch,stdin);
				scanf("%d",&num);
			}
			else
				assign[i++]=ch;
		}
		assign[i]='\0';
		///printf("%s\n",assign);
		if(!strcmp(assign,"push()")){
			stack[stacknum++]=num;
		}
		else if(!strcmp(assign,"pop")){
			stacknum--;
		}
		else if(assign[0]=='-'&&num==1)
			return 0;
		else
			printf("Wrong Operation!\n");
		if(stacknum>(size/2))
			size*=2;
		if(stacknum<=(size/2))
			size/=2;
        if(size==0){
            printf("The size of the stack is %d\n",k);
        }
        else
            printf("The size of the stack is %d\n",size);
		for(j=0;j<stacknum;j++){
			printf("%3d",stack[j]);
		}
		printf("\n");
	}
	return 0;
}

