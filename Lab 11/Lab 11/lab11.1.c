#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
	while(1){
		FILE *fp, *fp1;
		char str1[50]="d:\\x555JK\\Desktop\\Q1\\";
		char str2[50]="d:\\x555JK\\Desktop\\Q1\\";
		char str3[50],str4[50];
		char gen;
		int F=0,M=0,n=0;
		int age,agemax=0,agemin=1000;
		double	total=0.0, income=0.0,average=0.0;
		printf("Input filename:");
		scanf("%s",str3);
		strcat(str1,str3);
		fp=fopen(str1,"r");
		if(fp==NULL){
			printf("The file can not be opened!\n");
		}
		while(fscanf(fp,"%c %d %lf",&gen,&age,&income)!=EOF){
			if(gen=='F'){
				F++;n++;
			}
			if(gen=='M'){
				M++;n++;
			}
			if(age>agemax){
				agemax=age;
			}
			if(age<agemin){
				agemin=age;
			}
			total+=income;
			income=0;
		}
		average=(total/n);
		fclose(fp);
		printf("Output filename:");
		scanf("%s",str4);
		strcat(str2,str4);
		fp1=fopen(str2,"w");
		fprintf(fp1,"Female:%d\nMale:%d\n\nOldest:%d\nYoungest:%d\n\nAverage of income:%lf\n",F,M,agemax,agemin,average);
		fclose(fp1);
		printf("Analyze successfully!\n\n");
	} 
	return 0;
}
