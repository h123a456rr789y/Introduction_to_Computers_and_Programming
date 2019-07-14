#include<stdio.h>

void lexicalOrder(int now, int n){
    if(now > n){
        return;
	} else{
		printf("%d ", now);
	}

    lexicalOrder(now * 10, n);

	int i;
    if(now / 10 > 0){
        for(i = 1; i <= 9; i++){
            if(now + i <= n){
				printf("%d ", now + i);
                lexicalOrder((now + i) * 10, n);
            }
        }
    }
}

int main() {
	int i;

	printf("Please input n: ");
	int n;
	scanf("%d", &n);

    for(i = 1; i <= 9; i++){
		lexicalOrder(i, n);
    }

    return 0;
}
