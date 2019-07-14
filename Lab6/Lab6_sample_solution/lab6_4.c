#include <stdio.h>

int main() {
    char text[101];
    int length = 0;

    printf("Please input text:");

    scanf("%[^\n]100s", text);
    /*
        char tmp;
        tmp = getchar();
        while(tmp != '\n') {
            text[length] = tmp;
            tmp = getchar();
            length++;
        }
        text[length] = 0;
    */


    int idx = 0;
    while(text[idx]) {
        if(text[idx] == '#') {
            int i;
            int inverseEnd = idx - 1;
            if(inverseEnd > 0) {
                for(i = 0; i < inverseEnd / 2 + 1; i++) {
                    char tmp = text[i];
                    text[i] = text[inverseEnd - i];
                    text[inverseEnd - i] = tmp;
                }
            }
        }
        idx++;
    }

    printf("%s", text);


    return 0;
}
