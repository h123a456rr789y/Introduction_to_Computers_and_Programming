#include <stdio.h>
#include <string.h>
#define MAX 100
#include "stack.h"
int top=-1;
struct stk{
    char s[256];
    double val;
}stack[MAX];

int is_empty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int is_full(){
    return top==MAX;
}
void push(char s[],double val){
    if(is_full()){
        printf("Stack is full\n");
        return;
    }
    top++;
    strcpy(stack[top].s,s);
    stack[top].val=val;
    return;
}

void pop(){
    if(is_empty()){
        printf("Stack is empty\n");
        return ;
    }
    top--;
    return;
}
char* top_s(){
    return stack[top].s;
}
double top_val(){
    return stack[top].val;
}

void print_stack(){
    int i;
    for(i=0;i<=top;i++){
        printf("%s",stack[i].s);
    }
}
