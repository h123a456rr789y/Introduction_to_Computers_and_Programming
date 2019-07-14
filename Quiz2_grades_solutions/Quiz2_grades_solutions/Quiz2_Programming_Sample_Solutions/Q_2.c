#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int capacity;
    int length;
    char *data;
} DynaStr;

DynaStr *createStr();
int setStr(DynaStr * str, const char* cString);
int appendStr(DynaStr *str, const char *cString);
void printStr(const DynaStr * str);
void clearStr(DynaStr * str);
void deleteStr(DynaStr *str);

DynaStr *createStr(){
    DynaStr *newStr = (DynaStr*)malloc(sizeof(DynaStr));
    if(newStr == NULL){
        return NULL;
    }
	newStr->length = 0; //for printStr
    newStr->data = NULL; //for realloc
    newStr->capacity = 0;
    return newStr;
}

int setStr(DynaStr *str, const char *cString){
    int oldLength = str->length;
	str->length = 0;

	if(appendStr(str, cString)){
		return 1;
	}else{
		str->length = oldLength; //recover
		return 0;
	}
}

int appendStr(DynaStr *str, const char *cString){
    int cStrLen;
    //calculate string length
    for(cStrLen = 0; cString[cStrLen] != '\0'; cStrLen++){}
	int newStrLen = cStrLen + str->length;

    if(str->capacity < newStrLen){
        char *newdata = (char*)realloc(str->data, newStrLen * sizeof(char));
        if(newdata == NULL){ //realloc fail
            return 0;
        }
        str->data = newdata;
        str->capacity = newStrLen;
    }

    int i;
    for(i = 0; i < cStrLen; i++){
        str->data[str->length + i] = cString[i];
    }
	str->length = newStrLen;
	return 1;
}

void printStr(const DynaStr *str){
    int strLen = str->length;
    int i;
    for(i = 0; i < strLen; i++){
        putchar(str->data[i]);
    }
}

void clearStr(DynaStr *str){
    str->length = 0;
}

void deleteStr(DynaStr *str){
    free(str->data);
    free(str);
}


int main() {
	DynaStr *str = NULL;

    int opt;
    for(;;) {
        system("cls");
        printf(" -------------------------------------------------\n");
        printf("| 1. Create a Dynamic String.                    |\n");
        printf("| 2. Set the value of the Dynamic String.        |\n");
        printf("| 3. Append a C-String into the Dynamic String.  |\n");
        printf("| 4. Show the information of the Dynamic String. |\n");
        printf("| 5. Clear the Dynamic String.                   |\n");
        printf("| 6. Delete the Dynamic String.                  |\n");
        printf("| 7. Exit.                                       |\n");
        printf(" -------------------------------------------------\n");
        printf("What are you going to do? -> ");
        scanf("%d",&opt);

		if(opt != 1 && opt != 7 && str == NULL){
			printf("Please create a Dynamic String first!!\n");
			system("pause");
			continue;
		}

		switch(opt) {
        case 1: {
			if(str != NULL){
				printf("Dynamic String is already existed!!\n");
				system("pause");
			}else{
				str = createStr();
				if(str == NULL){
                    printf("Error: memory insufficient!!\n");
                    system("pause");
                }
			}
            break;
        }
        case 2: {
            printf("Please input string to set: ");
			char cStr[10001];
			scanf("%10000s", cStr);
			if(!setStr(str, cStr)){
				printf("Error: memory insufficient!!\n");
				system("pause");
			}
            break;
        }
        case 3: {
            printf("Please input string to append: ");
			char cStr[10001];
			scanf("%1000s", cStr);
			if(!appendStr(str, cStr)){
				printf("Error: memory insufficient!!\n");
				system("pause");
			}
            break;
        }
        case 4:
            printStr(str);
			printf("(length:%d, capacity:%d)\n\n", str->length, str->capacity);
			system("pause");
            break;
        case 5:
            clearStr(str);
            break;
        case 6:
            deleteStr(str);
            str = NULL;
            break;
        case 7:
            return 0;
        default:
            printf("Wrong input. Please enter input 1-7.\n");
            system("pause");
        }
    }

    if(str != NULL){
        deleteStr(str);
    }
    return 0;
}

