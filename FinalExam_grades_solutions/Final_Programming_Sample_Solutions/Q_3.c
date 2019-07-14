#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX_ITEM_NAME 101
#define EFFECT_COUNT 3

typedef struct {
    char name[MAX_ITEM_NAME];
    int effects[EFFECT_COUNT];
} Item;

Item * findItem(const char* itemName);

int itemLen = 0;
Item *itemList = NULL;

Item * findItem(const char* itemName) {
    int i;
    for(i = 0; i < itemLen; i++) {
        if(strcmp(itemList[i].name, itemName) == 0) return itemList + i;
    }
    return NULL;
}

int readLine(char *aLine, FILE *src) {
    if(fgets(aLine, 1000, src) != NULL) {
        int len = strlen(aLine);
        if(aLine[len - 1] == '\n') aLine[len - 1] = '\0'; //remove '\n'

        return 1;
    }
    return 0;
}

void printItem(FILE *out, const Item *tmpItem) {
    fprintf(out, "%8s %3d %3d %3d\n", tmpItem->name, tmpItem->effects[0], tmpItem->effects[1], tmpItem->effects[2]);
}

int main() {
    char aLine[1001];
    FILE *itemFile = fopen("items.txt", "r");
    FILE *formattedItems = fopen("formattedItems.txt", "w");


    printf("Load items from items.txt: \n");
    int lineCount;

    for(lineCount = 1; readLine(aLine, itemFile); lineCount++){
        char *tmpItemName = strtok(aLine, " ");
        if(tmpItemName == NULL) continue; //empty line

        if(findItem(tmpItemName) != NULL) {
            printf("Error happen at line %d, item \"%s\" already exist!!\n", lineCount, tmpItemName);
        } else {
            Item tmpItem;
            strcpy(tmpItem.name, tmpItemName);

            int i;
            for(i = 0; i < EFFECT_COUNT; i++) {
                char *tmpNum = strtok(NULL, " ");
                if(tmpNum == NULL) {
                    break;
                }
                tmpItem.effects[i] = atoi(tmpNum);
            }

            if(i < EFFECT_COUNT) {
                printf("Error happen at line %d, too few effect values!!\n", lineCount);
            } else if(strtok(NULL, " ") != NULL) { //can still split new int value
                printf("Error happen at line %d, too many effect values!!\n", lineCount);
            } else {
                printItem(formattedItems, &tmpItem);
                itemLen++;
                itemList = realloc(itemList, sizeof(Item) * itemLen);
                itemList[itemLen - 1] = tmpItem; //insert into list
            }
        }
    }
    fclose(itemFile);
    fclose(formattedItems);

    printf("Success load %d items!!\n\n", itemLen);

    FILE *playerFile = fopen("player.txt", "r");

    FILE *outputFile = fopen("result.txt", "w");
    char playerName[1001];

    printf("Calculate total effects from player.txt: \n");


    readLine(playerName, playerFile);
    fprintf(outputFile, "Player: %s\n", playerName);

    int effectSum[3] = {0};

    int i;
    //we should start from line 2
    for(lineCount = 2; readLine(aLine, playerFile); lineCount++){
        char *tmpItemName = strtok(aLine, " ");
        if(tmpItemName == NULL) continue; //empty line

        Item *tmpItem = findItem(tmpItemName);
        if(tmpItem != NULL) {
            printItem(outputFile, tmpItem);

            for(i = 0; i < EFFECT_COUNT; i++) {
                effectSum[i] += tmpItem->effects[i];
            }
        } else {
            printf("Error happen at line %d, cannot find item \"%s\"!!\n", lineCount, tmpItemName);
        }
    }
    fprintf(outputFile, "--------------------\n");
    fprintf(outputFile, "%8s %3d %3d %3d\n", "Total:", effectSum[0], effectSum[1], effectSum[2]);

    printf("Player: %s\n", playerName);
    printf("Total: %3d %3d %3d\n", effectSum[0], effectSum[1], effectSum[2]);

    fclose(playerFile);
    fclose(outputFile);
    free(itemList);
    return 0;
}
