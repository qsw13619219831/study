
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int judge(int*arr ,int judge_number,int lenth){
	if (judge_number <= *(arr + lenth)){
		return 1;
	}
	return 0;
}
int main(){
	int arr[][3] = { { 1, 2, 3 }, { 2, 3, 4 }, { 3, 4, 5 } };
	int lenth = (sizeof arr / sizeof arr[0][0])-1;
	int a;
	scanf("%d", &a);
	if (judge(arr, a, lenth)){
		printf("сп\n");
	}
	else{
		printf("нч\n");
	}
	system("pause");
	return 0;
}
