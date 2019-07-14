#include<stdio.h>

int main(void){
    int num;
    printf("Please enter a number:");
    scanf("%d",&num);

    switch(num){
        case 0: printf("  _ \n");
                printf(" | |\n");
                printf(" |_|\n");
                printf("   \n");
                break;
        case 1:printf(" |\n");
               printf(" |\n");
               break;
        case 2: printf("  _ \n");
                printf("  _|\n");
                printf(" |_ \n");
                break;
        case 3: printf("  _\n");
                printf("  _| \n");
                printf("  _| \n");
                break;
        case 4: printf("  |_| \n");
                printf("    | \n");
                break;
        case 5: printf("  _ \n ");
                printf(" |_  \n");
                printf("  _| \n");

                break;
        case 6: printf("  _\n");
                printf(" |_ \n");
                printf(" |_|\n");

                break;
        case 7: printf("   _\n");
                printf("    |\n");
                printf("    |\n");
                break;
        case 8: printf(" _\n");
                printf("|_|\n");
                printf("|_|\n");

                break;
        case 9: printf("  _  \n");
                printf(" |_|  \n");
                printf("  _| \n");
                break;
        default: printf("The number is illegal");
                break;

    }
    return 0;
}
