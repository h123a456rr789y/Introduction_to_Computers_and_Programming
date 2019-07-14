#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void){
    int year=2016,month=9,day=21;
    float temperature=23.54;
    printf("\"Data\"\t\t%d\\%02d\\%d\n",year,month,day);
    printf("\"Temperature\"\t%5.2f",temperature);


    return 0;
}
