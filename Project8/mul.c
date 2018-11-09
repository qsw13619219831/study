#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void mul(int x){
	for (int i = 1; i <= x; i++){
		for (int j = 1; j <= i; j++){
			printf("%d*%d=%d\t", j, i, i*j);
		}
		printf("\n");
	}
}
	
	int main(){
		int a = 0;
		scanf("%d", &a);
		mul(a);

	system("pause");
	return 0;
}