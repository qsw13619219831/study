#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
void judgment(int x){
	if (x % 400 != 0){
		if (x%4==0){
			printf("��");
		}
		else{
			printf("����");
		}
	}
	else{
		printf("����");
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