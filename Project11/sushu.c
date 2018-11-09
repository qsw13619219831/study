#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int judgment(int x){
	int i = 0;
	for ( i = 2; i < x; i++){
		if (x%i == 0){
			break;
		}
	}
	if (i == x){
		printf("是素数\n");
	}
	else{
		printf("不是素数\n");
	}
}
int main(){
	int a;
	for (;;){
		scanf("%d", &a);
		judgment(a);
	}
	system("pause");
	return 0;
}
