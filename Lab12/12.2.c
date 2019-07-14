#include<stdio.h>
#include<stdlib.h>
#include<string.h>




int main(void){
    FILE *fp;
    char A[100]="D:\\Users\\liyu6072\\Downloads\\Lab 12\\Lab 12\\Q_2\\";
    char B[100];
    printf("Please input game file path:");
    scanf("%s",B);
    strcat(A,B);
    fp=fopen(A,"rb");
    if(fp==NULL){
        printf("The file can not be opened!\n");
    }
    else{
        int hh,ha,hd,bh,ba,bd,validcode;
        fread(&hh,sizeof(int),1,fp);
        fread(&ha,sizeof(int),1,fp);
        fread(&hd,sizeof(int),1,fp);
        fread(&bh,sizeof(int),1,fp);
        fread(&ba,sizeof(int),1,fp);
        fread(&bd,sizeof(int),1,fp);
        printf("Hero: Hp:%5d, Att:%5d,Def%5d\n",hh,ha,hd);
        printf("Hero: Hp:%5d, Att:%5d,Def%5d\n\n",bh,ba,bd);
        fclose(fp);
        fp=fopen(A,"rb+");
        printf("Please input new value of hero:\n");
        scanf("%d %d %d",&hh,&ha,&hd);
        printf("Please input new value of boss:\n");
        scanf("%d %d %d",&bh,&ba,&bd);
        fwrite(&hh,sizeof(int),1,fp);
        fwrite(&ha,sizeof(int),1,fp);
        fwrite(&hd,sizeof(int),1,fp);
        fwrite(&bh,sizeof(int),1,fp);
        fwrite(&ba,sizeof(int),1,fp);
        fwrite(&bd,sizeof(int),1,fp);
        validcode=(hh+ha+hd)*(bh+ba+bd)%1234;
        fwrite(&validcode,sizeof(int),1,fp);
    }
    fclose(fp);





    return 0;
}
