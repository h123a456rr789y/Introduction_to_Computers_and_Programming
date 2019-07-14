#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
	FILE *fp;
	int n,i,j=0,k,l,a;
	int words=0,word=0,times=0,r=0;
	printf("How many files would you input:");
	scanf("%d",&n);
	char path[n][100];
	char text[n][50];
	char content[1000][100];
	char str[100];
	for(i=0;i<n;i++){
		strcpy(path[i],"d:\\x555JK\\Desktop\\testData\\Q2\\");
		printf("Please input file path:");
		scanf("%s",text[i]);
		strcat(path[i],text[i]);
	}
	for(i=0;i<n;i++){
		fp=fopen(path[i],"r");
		if(fp==NULL){
			printf("the file can't be opened.");
		}
		else{
			while(fscanf(fp,"%s",str)!=EOF){
				for(k=0;k<strlen(str);k++){
					str[k]=tolower(str[k]);
				}
				if(word==0){
					strcpy(content[word++],str);
					//printf("CHECK\n");
				}
				else{
					times=0;
					for(j=0;j<word;j++){
						if(!strcmp(str,content[j])){
							times++;
						}
					}
					if(times==0){
						strcpy(content[word++],str);
					//printf("CH\n");
					}
				}
			}
			fclose(fp);
		}
			printf("There are %d different string in those files.\n",word);
	}
		
	return 0;
}
