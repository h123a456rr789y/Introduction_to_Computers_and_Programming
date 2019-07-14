#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	char ch;
	printf("Please input plain text:");
	ch=getchar();
	int num=0,cnt;
	printf("output text:");
	while(ch!='\n'){
		if(ch=='0' || ch=='1'|| ch=='2' || ch=='3' || ch=='4' || ch=='5' || ch=='6' || ch=='7' || ch=='8' || ch=='9' ){
			num=num*10+ch-'0';
		} 
		else{	
			for(cnt=0;cnt<num;cnt++)
				printf("%c",ch);
				num=0; 
		}
	ch=getchar();
		
	}
	
	
	
	
	
	
	
	return 0;
}
