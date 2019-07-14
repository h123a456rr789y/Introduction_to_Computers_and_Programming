#include<stdio.h>

int main(void){
    int g;
    printf(" Input the grade:");
    scanf("%d",&g);

    if(g>=0 && g<=100){
        if (g>=90 && g<=100 )
        printf("The student get an A");
        else if (g>=80 && g<=89)
        printf("The student get an B");
        else if (g>=70 && g<=79)
        printf("The student get an C");
        else if (g>=60 && g<=69)
        printf("The student get an D");
        else
        printf("The student get an F");
    }
    else{
        printf("the grade is out of range");
    }
    return 0;
}
