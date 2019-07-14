#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SELECT_COUNT 10
#define CALC_COUNT 10

typedef struct {
    char sels[SELECT_COUNT];
    int cals[CALC_COUNT];
} Solution;

typedef struct {
    char id[101];
    char gender;
    Solution ans;
} AnsSheet;

void readSolution(FILE *fp, Solution *tar) {
    int i;

    for(i = 0; i < SELECT_COUNT; i++) {
        fscanf(fp, " %c", &(tar->sels[i])); //" %c" means ignore space, '\t', '\n' or other blank characters
    }

    for(i = 0; i < CALC_COUNT; i++) {
        fscanf(fp, "%d", &(tar->cals[i]));
    }
}

int evalScore(const Solution *tar, const Solution *src) {
    int score = 0;
    int i;

    for(i = 0; i < SELECT_COUNT; i++) {
        if(tar->sels[i] == src->sels[i]) {
            score +=5;
        }
    }

    for(i = 0; i < CALC_COUNT; i++) {
        if(tar->cals[i] == src->cals[i]) {
            score +=5;
        }
    }
    return score;
}

void readSheet(FILE *fp, AnsSheet *tar) {
    fscanf(fp, "%s", tar->id);
    fscanf(fp, " %c", &(tar->gender));
    readSolution(fp, &(tar->ans));
}

int main() {
    //read answer file
    FILE *ansFile = fopen("answer.txt", "r");
    if(ansFile == NULL) {
        printf("Cannot read answer.txt!!\n");
        return 1;
    }
    Solution ans;
    readSolution(ansFile, &ans);
    fclose(ansFile);

    FILE *studentList = fopen("fileList.txt", "r");
    int successCount = 0;

    if(studentList == NULL) {
        printf("Cannot read fileList.txt!!\n");
        return 1;
    } else {
        char filename[101];
        FILE *result = fopen("result.txt", "w");

        while(fgets(filename, 100, studentList) != NULL) {
            int len = strlen(filename);
            if(filename[len - 1] == '\n') filename[len - 1] = '\0'; //remove '\n'
            if(filename[0] == '\0') continue; //empty line

            FILE *studentFile = fopen(filename, "r");
            if(studentFile != NULL) {
                AnsSheet tmp;
                readSheet(studentFile, &tmp);
                fprintf(result, "%s %c\t%d\n", tmp.id, tmp.gender, evalScore(&(tmp.ans), &ans));
                fclose(studentFile);
                successCount++;
            } else {
                printf("Error happened: Cannot read %s!!\n", filename);
            }
        }
        fclose(result);
    }
    fclose(studentList);

    printf("Processed %d file successfully\n", successCount);
    return 0;
}

