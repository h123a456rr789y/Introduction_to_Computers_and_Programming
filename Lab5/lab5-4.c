#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	int i;
	char c;
	
	printf("Please input shift: ");
	scanf("%d",&i);
	fflush(stdin);
	printf("PLease input plain text: ");
	c=getchar();
	printf("Cipher text: ");
	while(c!='\n'){
		if(isalpha(c)){
			char up;
			up=toupper(c);
			if(up+i>90)
				up=up+i-26;
			else if(up+i<65)
				up=up+i+26;
			else
				up=up+i;
			printf("%c",up);
		}
		else
			printf("%c",c);
		c=getchar();
	}
}
