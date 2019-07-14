#include<stdio.h>

int main(void){
	char text[101],stack[100],temptext[100];
	int i=0,stacklen=0,k=0,j=0;
	int begin;
	char ch;
	printf("Please use '(' and ')' to meak reverse area,your input:\n");
	ch=getchar();
	
	/*use a stackarray to record the position of ( and ) so that 
	you can know the range that 
	you have to reverse your text!!
	*/
	while(ch!='\n'){
		if(ch=='(')
			stack[stacklen++]=i;
		else if (ch==')'){
			begin=stack[--stacklen];
			for(k=0,j=begin;j<i;k++,j++){
				temptext[k]=text[j];
			}
			for(k--,j=begin;k>=0;k--,j++){
				text[j]=temptext[k];
			}
		}
		else
			text[i++]=ch;
		ch=getchar();
	}
	text[i]='\0';
	printf("%s",text);
	return 0;
}

