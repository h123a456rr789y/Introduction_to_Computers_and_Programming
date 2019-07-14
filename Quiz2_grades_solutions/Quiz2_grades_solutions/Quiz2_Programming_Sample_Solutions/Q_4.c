#include <stdio.h>
#include <stdlib.h>
#define MAX_CYCLE 100
#define MAX_SEQ 10000
#define MAX_SEQ_LEN 100

int availNums[MAX_CYCLE] = {0};
int bestDeep = 0;
int bestSeqCount = 0;
int bestSeq[MAX_SEQ][MAX_SEQ_LEN];

int dfs(int tryPick, int *pickSeq, int deep);
int cycleLen;
int main() {
    int min, max;
    printf("Please input max number: ");
    scanf("%d", &max);

    printf("Please input min number: ");
    scanf("%d", &min);

    if(min > max){
        printf("min should not larger than max!!");
        return 1;
    }

    cycleLen = max - min + 1;

    int curNum;
    printf("Please input start number: ");
    scanf("%d", &curNum);
    curNum-= min; //shift min number
    availNums[curNum]++;

    printf("Please input available numbers: ");
    int num;
    scanf("%d", &num);
    do {
        availNums[num - min]++; //shift min number
        scanf("%d", &num);
    } while(num != 0);

    int tmpSeq[100];
    dfs(curNum, tmpSeq, 0);

    int i, j;
    printf("There are %d longest Sequences(length %d): \n", bestSeqCount, bestDeep);
    for(j =0; j < bestSeqCount; j++) {
        for(i = 0; i < bestDeep; i++) printf("%d ", bestSeq[j][i] + min); //add shift
        printf("\n");
    }
    return 0;
}

int dfs(int tryPick, int *pickSeq, int deep) {
    if(availNums[tryPick] > 0) { //can pick
        pickSeq[deep] = tryPick;
        deep++;
        availNums[tryPick]--; //remove it
        int canPickMore ;

        int nextNum = (tryPick + 1) % cycleLen;
        int preNum = (tryPick - 1 + cycleLen) % cycleLen;

        //try pick current + 1
        canPickMore = dfs(nextNum, pickSeq, deep);

        if(preNum != nextNum){
             //try pick current - 1
            canPickMore |= dfs(preNum, pickSeq, deep);
        }//else no need to check preNum

        if(!canPickMore) { //sequence end
            if(deep >= bestDeep) { //better than the best sequence
                if(deep > bestDeep) {
                    bestSeqCount = 0; //rest
                    bestDeep = deep;
                }
                int i;
                for(i = 0; i < deep; i++) {
                    bestSeq[bestSeqCount][i] = pickSeq[i];
                }
                bestSeqCount++;
            }
        }
        availNums[tryPick]++; //undo
        return 1;
    } else { //can not pick
        //printf("fail put %d\n", tryPick);
        return 0;
    }
}
