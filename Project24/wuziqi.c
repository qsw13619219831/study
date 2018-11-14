#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <math.h>
#include<time.h>
int panduan1(char arr[][15]){
	for (int i = 0; i < 15; i++){//横着判断
		for (int j = 0; j < 15; j++){
			if (arr[i][j] == 'x'&&arr[i][j + 1] == 'x'&&arr[i][j + 2] == 'x' && arr[i][j + 3] == 'x'&& arr[i][j + 4] == 'x'){
				return 1;
			}
		}
	}
	for (int i = 0; i < 15; i++){//竖着判断
		for (int j = 0; j < 15; j++){
			if (arr[i][j] == 'x'&&arr[i + 1][j] == 'x'&&arr[i + 2][j] == 'x' && arr[i + 3][j] == 'x'&& arr[i + 4][j] == 'x'){
				return 1;
			}
		}
	}
	for (int i = 0; i < 15; i++){//反斜着判断
		for (int j = 0; j < 15; j++){
			if (arr[i][j] == 'x'&&arr[i + 1][j + 1] == 'x'&&arr[i + 2][j + 2] == 'x' && arr[i + 3][j + 3] == 'x'&& arr[i + 4][j + 4] == 'x'){
				return 1;
			}
		}
	}
	for (int i = 0; i < 15; i++){//正斜着判断
		for (int j = 0; j < 15; j++){
			if (arr[i][j] == 'x'&&arr[i -1][j + 1] == 'x'&&arr[i - 2][j + 2] == 'x' && arr[i - 3][j + 3] == 'x'&& arr[i - 4][j + 4] == 'x'){
				return 1;
			}
		}
	}
	return 0;
}
int panduan2(char arr[][15]){
	for (int i = 0; i < 15; i++){//横着判断
		for (int j = 0; j < 15; j++){
			if (arr[i][j] == 'o'&&arr[i][j + 1] == 'o'&&arr[i][j + 2] == 'o' && arr[i][j + 3] == 'o'&& arr[i][j + 4] == 'o'){
				return 1;
			}
		}
	}
	for (int i = 0; i < 15; i++){//竖着判断
		for (int j = 0; j < 15; j++){
			if (arr[i][j] == 'o'&&arr[i + 1][j] == 'o'&&arr[i + 2][j] == 'o' && arr[i + 3][j] == 'o'&& arr[i + 4][j] == 'o'){
				return 1;
			}
		}
	}
	for (int i = 0; i < 15; i++){//反斜着判断
		for (int j = 0; j < 15; j++){
			if (arr[i][j] == 'o'&&arr[i + 1][j + 1] == 'o'&&arr[i + 2][j + 2] == 'o' && arr[i + 3][j + 3] == 'o'&& arr[i + 4][j + 4] == 'o'){
				return 1;
			}
		}
	}
	for (int i = 0; i < 15; i++){//正斜着判断
		for (int j = 0; j < 15; j++){
			if (arr[i][j] == 'o'&&arr[i - 1][j + 1] == 'o'&&arr[i - 2][j + 2] == 'o' && arr[i - 3][j + 3] == 'o'&& arr[i - 4][j + 4] == 'o'){
				return 1;
			}
		}
	}
	return 0;
}
void fun1(char arr[][15]){
	for (int i = 0; i < 15; i++){
		for (int j = 0; j < 15; j++){
			printf("|%c", arr[i][j]);

		}
		printf("\n");
	}
}
int main(){
	char arr1[30][15];
	for (int i = 0; i < 15; i++){
		for (int j = 0; j < 15; j++){
			if (i==0){
				arr1[i][j] = 'a'+j;
			}
			else if (j==0){
				arr1[i][j] = 'A'+i;
			}
			else{
				arr1[i][j] = ' ';
			}
		}
	}
	fun1(arr1);
	int count = 2;
	int d = rand() % 10;
	for (;;) {
		if (count % 2 == 0){
			int a, b;	
			if (panduan1(arr1)){  //判断有没有五颗
				printf("you win\n");
				break;
			}
			else{
				erro:
				scanf("%d %d", &a, &b);//人下棋
				if (arr1[a][b] == ' '){//判断有无棋子
					arr1[a][b] = 'x';
					//fun1(arr1);
					printf("\n");
					count++;
				}
				else{
					printf("请重下\n");
					goto erro;
				}
			}
		}                     
		else{
			if (panduan2(arr1)){  //判断有没有五颗
				printf("you lost\n");
				break;
			}
		
			else{
				for (;;){
					int c = rand() % 15;
					int d = rand() % 15;
					if (arr1[c][d] == ' '){
						arr1[c][d] = 'o';
						break;
					}//电脑下棋
					else{
						printf("不好意思，我想一下\n");

					}
				}
				fun1(arr1);
				printf("\n");
				count++;
			}
		}
	}
	system("pause");
}