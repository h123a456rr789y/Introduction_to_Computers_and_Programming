#include<stdio.h> 
#define MAX_TABLE_SZ 10 
int times=0;
void move(char a,char b,char c,int n){
	if(n==1){
		printf("Move the sheet form %c to %c\n",a,c);
		times++;
		return;
	}
		move(a,c,b,n-1);
		printf("Move the sheet from %c to %c\n",a,c);
		times++;
		move(b,a,c,n-1);
}



int main(void) {
	int n;
	printf("Enter the number of the disks:");
	scanf("%d",&n);
	move('A','B','C',n);
	printf("Need at least %d move.\n",times);
	return 0; 
}
