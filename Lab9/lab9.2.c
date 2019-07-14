#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
	int i=0,j,strnum,strnum1;
	char func[50],s[50],s1[50],cot[100],str[6][100]={0};
	int checkassign[6]={0},;
	/*Step1:ckeck the function that you are going to use
	  Step2:use s,s1 to check the thaing you want to deal with and check the a[3] which is the string(number0~5)
	  Step3:write the function 
	  Step4:write to special conditions ex. invalid cannt be assign cannot clear etc.*/
	while(scanf("%s",func)){
		if(!strcmp(func,"assign")){
			scanf("%s",s);
				if(s[0]=='s'&& s[1]=='t'&&s[2]=='r'&&s[3]<='5'&&s[3]>='0'){
					strnum=s[3]-'0';
					//to check wether already assign or not.Use a flag to check
					if(checkassign[strnum]==1)
						printf("str%d has already been assign!\n",strnum);
					scanf("%s",str[strnum]);
					checkassign[strnum]=1;
				}
				else 
					printf("Invalid\n");
		}
		if(!strcmp(func,"copy")){
			scanf("%s %s",s,s1);
				if(s1[0]=='s'&&s1[1]=='t'&&s1[2]=='r'&&s1[3]<='5'&&s1[3]>='0'){
					strnum=s[3]-'0';
					strnum1=s1[3]-'0';
					if (str[strnum1][0]=='\0'){
						printf("Cannot copy from an empty string!\n");
					}
					else
						strcpy(str[strnum],str[strnum1]);
					
				}
				else{
					strnum=s[3]-'0';
					strcpy(str[strnum],s1);
				}
		}
		if(!strcmp(func,"clear")){
			scanf("%s",s);
			strnum=s[3]-'0';
			if(str[strnum][0]=='\0'){
				printf("Cannot clear an empty string!\n");
			}
			str[strnum][0]='\0';
			
		}
		if(!strcmp(func,"show")){
		if(strlen(str[0])==0&&strlen(str[1])==0&&strlen(str[2])==0&&strlen(str[3])==0&&strlen(str[4])==0&&strlen(str[5])==0)
			printf("empty\n");	
			for(i=0;i<6;i++){
				if(strlen(str[i])!=0){	
					printf("str%d:",i);
					printf("%s\n",str[i]);
				}
			}
		}
		if(!strcmp(func,"cat")){
			scanf("%s %s",s,s1);
			strnum=s[3]-'0';
			strnum1=s1[3]-'0';
			if (str[strnum1][0]=='\0'){
				printf("Cannot concatenate from an empty string!\n");
			}
			else
			strcat(str[strnum],str[strnum1]);	
		}
		if(!strcmp(func,"cmp")){
			scanf("%s %s",s,s1);
			if(s1[0]=='s'&&s1[1]=='t'&&s1[2]=='r'&&s1[3]<='5'&&s1[3]>='0'){
				strnum=s[3]-'0';
				strnum1=s1[3]-'0';
				if(strcmp(str[strnum],str[strnum1])==0)
					printf("the same\n");
				else 
					printf("not the same\n");
			}
			else{
				strnum=s[3]-'0';
				if(strcmp(str[strnum],s1)==0)
					printf("the same\n");
				else 
					printf("not the same\n");
			}
		}
	}
	return 0;
}
