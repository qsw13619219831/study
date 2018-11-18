#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX_CHANG 10
#define MAX_KUAN 10
#define boom 10
void usermap(char arr1[MAX_CHANG + 2][MAX_KUAN + 2], char arr2[MAX_CHANG + 2][MAX_KUAN + 2]){
	for (int c = 0; c < MAX_CHANG;c++){
		printf(" %d ", c+1);
	}
	printf("\n");
	for (int i = 1; i <= MAX_CHANG; i++){
		for (int j = 1; j <= MAX_KUAN; j++){
			arr1[i][j] = '~';
			}
	}
	for (int i = 1; i < MAX_CHANG; i++){
		for (int j = 1; j < MAX_KUAN; j++){
			arr2[i][j] = '0';

		}
	}
	//设置雷的数量
	int count = 0;
	while (count < boom){
		int a = rand() % 10 + 1;
		int b = rand() % 10 + 1;
		if (arr2[a][b] == '0'){
			arr2[a][b] = '1';
			count++;
		}
		else{
			continue;
		}
	}
}


void daying(char arr1[MAX_CHANG+2][MAX_KUAN+2]){

	for (int i = 1; i <= MAX_CHANG; i++){
		for (int j = 1; j <= MAX_KUAN; j++){
			printf(" %c ", arr1[i][j]);
		}
		printf("%02d|", i);
		printf("\n");
		printf("\n");
	}
}
void game(){
	int count = 0;
	char arr1[MAX_CHANG + 2][MAX_KUAN + 2];
	char arr2[MAX_CHANG + 2][MAX_KUAN + 2];
	while (1){
		if (count == MAX_CHANG*MAX_KUAN - boom){
			printf("你赢了!!!!\n");
			break;
		}
		else{
			int a, b;
			usermap(arr1,arr2);
			 daying(arr1);
			printf("请输入要扫的雷的坐标\n");
			scanf("%d %d", &a, &b);
			

		}
	}
}

void start(){
	while (1){
		int choice = menu();
		if (choice == 1){//退出
			break;
		}
		else if (choice == 0){
			game();
		}
		else{
			printf("请选择1或者2!!!!!!!!!!!!!!!\n");
		}
	}
}


int menu(){
	printf("****************************************\n");
	printf("1.开始游戏\n");
	printf("2.结束游戏\n");
	printf("****************************************\n");
	int a;
	scanf("%d", &a);
	if (a == 1){
		return 0;
	}
	else if (a == 2){
		return 1;
	}
	else{
		return 2;
	}
}


 int main(){
	start();
	system("pause");
	return 0;
}