#include<stdio.h>

void reverseText(char *start, char *end) {
    end--;//move to last char
    while(start < end) {
        char tmp = *end;
        *end = *start;
        *start = tmp;
        start++;
        end--;
    }
}

int main() {
    int rStack[100];
    int rStackSize = 0;

    char text[101];
    int textLen = 0;

    printf("Please use '(' and ')' to mark reverse area, your input:\n");
    char ch;
    ch = getchar();

    do {
        if(ch =='(') {
            rStack[rStackSize++] = textLen;
        } else if(ch ==')') {
            if(rStackSize > 0){
                reverseText(text + rStack[--rStackSize], text + textLen);
            }else{
                reverseText(text, text + textLen); //from start
            }
        } else {
            text[textLen++] = ch;
        }
    } while((ch = getchar()) != '\n');

    while(rStackSize > 0){ //stack is not empty
        reverseText(text + rStack[--rStackSize], text + textLen);
    }

    text[textLen] = '\0';

    printf("Result: \n%s", text);
    return 0;
}
