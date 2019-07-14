#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define COMMAND_LEN 101
#define MAX_ARGS_LEN 10
#define MAX_NAME_LEN 101


void decodeStr(char *tar, char *src, char bracket) { //when tar == src it still works because new length is always <= old length
    int bracketMode = 0;
    char ch;
    int len = 0; //new length

    for(ch = *src; ch != '\0'; ch = *(++src)) {
        if(bracketMode == 1) {
            if(ch == bracket) {
                bracketMode = -1; //mark as just exit bracket
            } else {
                tar[len++] = ch; //just copy
            }
        } else {
            if(ch == bracket) {
                if(bracketMode == -1) { //just exit bracket
                    tar[len++] = ch; //add addition bracket
                }
                bracketMode = 1; //
            } else {
                tar[len++] = ch;
                bracketMode = 0;
            }
        }
    }
    tar[len] = '\0'; //end string
}

int splitStr(const char *str, char seg[][MAX_NAME_LEN], char split, char ignore, char bracket) {
    int preSegEnd = 0;
    int ignoreMode = 0;
    int bracketMode = 0;

    int segLen = 0;
    int segCount = 0;

    char ch;
    for(ch = *str; ch == split; ch = *(++str)); //move cursor to non-split char

    for(ch = *str; ch != '\0'; ch = *(++str)) { //read each char of string until '\0'
        if(bracketMode) {
            seg[segCount][segLen++] = ch;
            if(ch == bracket) {
                bracketMode = 0; // exit bracket mode
            }
        } else  if(ch == split) {
            if(!ignoreMode) preSegEnd = 1; //mark this segment string end, but not actually do it
            continue;
        } else { //other character
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

            if(ch == bracket) { //not in bracket mode
                bracketMode = 1; //enter bracket mode
            }
        }
    }
    seg[segCount++][segLen] = '\0'; //end segment string
    return segCount;
}

void showType1Info(char seg[][MAX_NAME_LEN]) {
    decodeStr(seg[1], seg[1], '\'');
    printf("\"%s\" is a type 1 command\nWith 1 argument: \"%s\"", seg[0], seg[1]);
}

void showType2Info(char seg[][MAX_NAME_LEN], const char *preposition) {
    if(strcmp(seg[2],preposition) != 0) {
        printf("Wrong preposition: \"%s\"!!\n", seg[2]);
        return;
    }

    char values[MAX_ARGS_LEN][MAX_NAME_LEN];
    int valuesCount;

    valuesCount = splitStr(seg[1], values, ',', '\0', '\'');

    printf("\"%s\" is a type 2 command with preposition: \"%s\"\n"
           "1 argument list: ", seg[0], seg[2]);
    int i;
    for(i = 0; i < valuesCount; i++) {
        decodeStr(values[i], values[i],'\'');
        printf("\"%s\" ", values[i]);
    }
    decodeStr(seg[3], seg[3], '\'');
    printf("\nand 1 tail argument: \"%s\"", seg[3]);
}

int main() {
    for(;;) {
        printf("Please input command: \n");
        char command[COMMAND_LEN];
        scanf("%[^\n]",command);

        char values[MAX_ARGS_LEN][MAX_NAME_LEN];
        int valuesCount;
        valuesCount = splitStr(command, values, ' ', ',', '\'');

        char *commandHead = values[0];

        if(strcmp(commandHead, "create") == 0) {
            showType2Info(values, "as");
        } else if(strcmp(commandHead, "insert") == 0) {
            showType2Info(values, "into");
        } else if(strcmp(commandHead, "remove") == 0) {
            showType2Info(values, "from");
        } else if(strcmp(commandHead, "delete") == 0) {
            showType1Info(values);
        } else if(strcmp(commandHead, "view") == 0) {
            showType1Info(values);
        } else if(strcmp(commandHead, "exit") == 0) {
            return 0;
        } else {
            printf("Unknown command \"%s\"\n", commandHead);
        }

        fflush(stdin);
        printf("\n\n");
    }
    return 0;
}
