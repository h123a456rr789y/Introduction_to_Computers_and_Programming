#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING 1000

int main() {
    char tmp[101];
    char strList[MAX_STRING][101];
    int listSize = 0;
    int diffStrCount = 0;
    int fileCount;
    printf("How many files would you input: ");
    scanf("%d", &fileCount);

    int j;
    for(j =0; j < fileCount; j++) {
        fflush(stdin);
        printf("Please input file path: ");
        scanf("%100[^\n]s", tmp);

        FILE *fp = fopen(tmp, "r");
        if(!fp) {
            printf("File not found !!\n");
            return 1;
        }

        while(fscanf(fp, "%100s", tmp) != EOF) {
            int i;
            int hasFound = 0;

            for(i = 0; i < listSize; i++) { //search in list
                if(strcasecmp(tmp, strList[i]) == 0) { //ignore case
                    hasFound = 1;
                    break;
                }
            }

            if(!hasFound) {
                diffStrCount++;
                strcpy(strList[listSize], tmp); //add to list
                listSize++;
            }
        }
        fclose(fp);
    }

    printf("There are %d different string in those files.\n", diffStrCount);
    return 0;
}
