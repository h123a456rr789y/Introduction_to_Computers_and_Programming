#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    while(1)
    {
        char filename[50];
        FILE *fin, *fout;
        char sex;
        int age;
        double income;

        printf("Input filename: ");
        scanf("%s", filename);
        fin = fopen(filename, "r");
        if(fin == NULL)
        {
            fputs("Input file error\n", stderr);
            continue;
        }
        //Read file until to the end of file (EOF)
        int count_f = 0, count_m = 0, count = 0;
        int max_age = -1, min_age = 10000000;
        double avg_income = 0.0;
        while(fscanf(fin, "%c %d %lf\n", &sex, &age, &income) != EOF)
        {
            // f or m
            if(sex == 'F')      count_f++;
            else if(sex == 'M') count_m++;
            // age
            if(age > max_age)   max_age = age;
            if(age < min_age)   min_age = age;
            // income
            avg_income += income;
            count++;
        }

        avg_income /= (double)count;
        printf("Output filename: ");
        scanf("%s", filename);
        fout = fopen(filename, "w");
        if(fout == NULL)
        {
            fputs("Output file error\n", stderr);
            continue;
        }
        fprintf(fout, "Female : %d\nMale : %d\n\n", count_f, count_m);
        fprintf(fout, "Oldest : %d\nYoungest : %d\n\n", max_age, min_age);
        fprintf(fout, "Average of income : %lf\n", avg_income);
        printf("Analyze successfully!\n\n");

        fclose(fout);
        fclose(fin);

    }
    return 0;
}
