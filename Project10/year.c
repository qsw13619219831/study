#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
void judgment(int x){
	if (x % 400 != 0){
		if (x%4==0){
			printf("是");
		}
		else{
			printf("不是");
		}
	}
	else{
		printf("不是");
	}
}

int main(){
	int a;
	for (;;){
		scanf("%d", &a);
		judgment(a);
	}
	system("pasuse");
	return 0;
}