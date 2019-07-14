#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define COMMAND_LEN 101
#define MAX_NAME_LEN 101
#define MAX_TABLE_LEN 10

#define MAX_COLUMN_LEN 10
#define MAX_ROW_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char columnNames[MAX_COLUMN_LEN][MAX_NAME_LEN];
    double columnValues[MAX_COLUMN_LEN][MAX_ROW_LEN];
    int columnCount;
    int rowCount;
} Table;

int tableCount = 0;
Table tables[MAX_TABLE_LEN];

void initalTable(Table *tar, const char *name, const char columns[][MAX_NAME_LEN], int columnCount) {
    tar -> columnCount = columnCount;
    tar -> rowCount = 0;

    int i;
    for(i = 0; i < columnCount; i++) {
        strcpy(tar -> columnNames[i], columns[i]);
    }
    strcpy(tar -> name, name);
}

int insertIntoTable(Table *tar, const char values[][MAX_NAME_LEN], int valuesCount) {
    if(valuesCount != tar -> columnCount) return 0;

    int i;
    for(i = 0; i < valuesCount; i++) {
        tar -> columnValues[tar -> rowCount][i] = atof(values[i]);
    }

    tar -> rowCount++;

    return 1;
}

int removeFromTable(Table *tar, const char values[][MAX_NAME_LEN], int valuesCount) {
    if(valuesCount != tar -> columnCount) return -1;

    double tmpValues[MAX_COLUMN_LEN];

    int i, j;
    for(i = 0; i < valuesCount; i++) {
        tmpValues[i] = atof(values[i]);
    }

    int removeCount = 0;

    int markToRemove[MAX_ROW_LEN] = {};

    for(j = 0; j < tar -> rowCount; j++) {
        int toRemove = 1;
        for(i = 0; i < tar -> columnCount; i++) {
            if(tar -> columnValues[j][i] != tmpValues[i]) {
                toRemove = 0;
                break;
            }
        }
        if(toRemove) {
            markToRemove[j] = 1;
            removeCount++;
        }
    }

    int toOverwrite = 0;
    for(j = 0; j < tar -> rowCount; j++) {
        if(!markToRemove[j]) { //rows to keep
            if(j != toOverwrite) { //skip overwrite self
                for(i = 0; i < tar -> columnCount; i++) {
                    tar -> columnValues[toOverwrite][i] = tar -> columnValues[j][i];
                }
            }
            toOverwrite++;
        }
    }

    tar -> rowCount -= removeCount;

    return removeCount;
}

int splitStr(const char *str, char seg[][MAX_NAME_LEN], char split, char ignore) {
    int preSegEnd = 0;
    int ignoreMode = 0;
    int segLen = 0;
    int segCount = 0;

    char ch;
    for(ch = *str; ch == split; ch = *(++str)); //move cursor to non-split char

    for(ch = *str; ch != '\0'; ch = *(++str)) { //read each char of string until '\0'
        if(ch == split) {
            if(!ignoreMode) preSegEnd = 1; //mark this segment string end, but not actually do it
            continue;
        } else {
            if(ch == ignore) {
                preSegEnd = 0; //cancel segment end
                ignoreMode = 1; //enter ignore split mode
            } else {
                ignoreMode = 0;
            }
            if(preSegEnd) {
                seg[segCount++][segLen] = '\0'; //end segment string
                segLen = 0;
                preSegEnd = 0;
            }
            seg[segCount][segLen++] = ch;
        }
    }
    seg[segCount++][segLen] = '\0'; //end segment string
    return segCount;
}

int findTable(const char *name) {
    int i;
    for(i = 0; i < tableCount; i++) {
        if(strcmp(tables[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int findTableInfo(const char *name) {
    int idx = findTable(name);
    if(idx == -1) printf("Error: Can not find table: \"%s\"\n", name);
    return idx;
}

int delTable(const char *name) {
    int idx = findTableInfo(name);

    if(idx == -1) return 0;
    if(tableCount > 1) {
        tables[idx] = tables[tableCount - 1];
    }
    tableCount--;
    return 1;
}

int viewTable(const char *name) {
    int idx = findTableInfo(name);
    if(idx == -1) return 0;
    Table *tar = &tables[idx];

    int i, j;
    for(i = 0; i < tar -> columnCount; i++) {
        printf("%s\t", tar -> columnNames[i]);
    }

    for(j = 0; j < tar -> rowCount; j++) {
        printf("\n");
        for(i = 0; i < tar -> columnCount; i++) {
            printf("%5.2f\t", tar -> columnValues[j][i]);
        }
    }
    printf("\n");
    return 1;
}

int chkPrepos(const char *input, const char *expect) {
    if(strcmp(input, expect) != 0) {
        printf("Wrong preposition: \"%s\"!!\n", input);
        return 0;
    }
    return 1;
}

int main() {
    for(;;) {
        printf("There are %d table(s) in the database.\n", tableCount);
        char command[COMMAND_LEN];
        scanf("%[^\n]",command);
        char values[MAX_COLUMN_LEN][MAX_NAME_LEN];
        int valuesCount;
        valuesCount = splitStr(command, values, ' ', ',');

        char *commandHead = values[0];
        char *remain = values[1];

        char listItem[MAX_COLUMN_LEN][MAX_NAME_LEN];
        int listCount;
        char *preposition = 0;
        char *tableName = 0;

        if(valuesCount == 4) { //type 2 command
            preposition = values[2];
            tableName = values[3];
            listCount = splitStr(values[1], listItem, ',', '\0');
        }

        if(strcmp(commandHead, "create") == 0) {
            if(valuesCount == 4 && chkPrepos(preposition, "as")) {
                if(tableCount < MAX_TABLE_LEN) {
                    if(findTable(tableName) == -1) {
                        initalTable(&tables[tableCount], tableName, listItem, listCount);
                        tableCount++;
                        printf("Success !!\n");
                    } else {
                        printf("Error: Table \"%s\" is already exist!!\n", tableName);
                    }
                } else {
                    printf("You can only have %d tables\n", MAX_TABLE_LEN);
                }
            }
        } else if(strcmp(commandHead, "insert") == 0) {
            if(valuesCount == 4 && chkPrepos(preposition, "into")) {
                int tableIdx = findTableInfo(tableName);
                if(tableIdx != -1) {
                    if(insertIntoTable(&tables[tableIdx], listItem, listCount)) {
                        printf("Success !!\n");
                    } else {
                        printf("Error: Column count not match!!\n");
                    }
                }
            }
        } else if(strcmp(commandHead, "remove" ) == 0) {
            if(valuesCount == 4 && chkPrepos(preposition, "from")) {
                int tableIdx = findTableInfo(tableName);
                if(tableIdx != -1) {
                    int removeCount = removeFromTable(&tables[tableIdx], listItem, listCount);
                    if(removeCount == -1) {
                        printf("Error: Column count not match!!\n");
                    } else {
                        printf("Success remove %d row(s) from %s!!\n", removeCount, tableName);
                    }
                }
            }
        } else if(strcmp(commandHead, "delete") == 0) {
            if(delTable(remain)) {
                printf("Success !!\n");
            }
        } else if(strcmp(commandHead, "view") == 0) {
            viewTable(remain);
        } else if(strcmp(commandHead, "exit") == 0) {
            return 0;
        } else {
            printf("Unknown command \"%s\"\n", commandHead);
        }
        fflush(stdin);
        printf("\n");
    }
    return 0;
}
