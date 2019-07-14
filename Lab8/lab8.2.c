#include<stdio.h>
#include<stdlib.h>

void swap(int *p,int *q){
	int temp;
	temp=*p;
	*p=*q;
	*q=temp;
}
void Bubble(int a[],int n){
	int i,j;
	for(i=1;i<n;i++){
		for(j=0;j<n-i;j++){
			if(a[j]>a[j+1]){
				swap(a+j,a+j+1);
			}
		}
	}
}
int main(void){
	int size;
	int i;
	printf("Input the size:");
	scanf("%d",&size);
	int a[size];
	printf("Before the sort:");
	for(i=0;i<size;i++){
		scanf("%d",&a[i]);
	}
	printf("\n");
	Bubble(a,size);
	printf("Ater sort:");
	for(i=0;i<size;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
