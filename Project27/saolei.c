#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX_CHANG 15
#define MAX_KUAN 15
#define boom 10
void usermap(char arr1[MAX_CHANG + 2][MAX_KUAN + 2], char arr2[MAX_CHANG + 2][MAX_KUAN + 2]){
	//�������ֻ�����ʼ���û���ͼ�ʹ����ͼ ��һ����Ϸֻ����һ��

	printf("\n");
	for (int i = 1; i <= MAX_CHANG; i++){
		for (int j = 1; j <= MAX_KUAN; j++){
			arr1[i][j] = '*';//�û���ͼ
			}
	}
	for (int i = 1; i <= MAX_CHANG; i++){
		for (int j = 1; j <= MAX_KUAN; j++){
			arr2[i][j] = '0';//�����ͼ

		}
	}
	for (int i = 0; i <= MAX_CHANG+1; i++){
		arr2[i][0] = '0' ;
	}
	for (int i = 0; i <= MAX_CHANG+1; i++){
		arr2[0][i] = '0';
	}
	for (int i = 0; i <= MAX_CHANG+1; i++){
		arr2[i][MAX_CHANG+1] = '0';
	}
	for (int i = 0; i <= MAX_CHANG+1; i++){
		arr2[MAX_CHANG+1][i] = '0';
	}
	//�����׵�����
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


int chuli(char arr1[MAX_CHANG + 2][MAX_KUAN + 2], char arr2[MAX_CHANG + 2][MAX_KUAN + 2], int a, int b){
	if (a > MAX_CHANG || b >MAX_CHANG || a <= 0 || b <= 0){
		return 0;
	}
	else if (arr1[a][b] == 'O'){
		return 0;
	}
		else if (arr2[a][b] == '0'){
			int counte = (arr2[a - 1][b - 1] - '0') +
				(arr2[a - 1][b] - '0') +
				(arr2[a - 1][b + 1] - '0') +
				(arr2[a + 1][b] - '0') +
				(arr2[a + 1][b + 1] - '0') +
				(arr2[a + 1][b - 1] - '0') +
				(arr2[a][b + 1] - '0') +
				(arr2[a][b - 1] - '0');
			arr1[a][b] = counte + '0';
		
			//��Χ�˸����ӵ���ֵ���
			if (arr1[a][b] == '0'){
			//����ݹ�ѭ������
				arr1[a][b] = 'O';
				return chuli(arr1, arr2, a - 1, b - 1), chuli(arr1, arr2, a - 1, b), chuli(arr1, arr2, a - 1, b + 1), chuli(arr1, arr2, a, b - 1), chuli(arr1, arr2, a, b + 1), chuli(arr1, arr2, a + 1, b - 1), chuli(arr1, arr2, a + 1, b + 1), chuli(arr1, arr2, a + 1, b);
			}
			else{
				return 0;
			}
			
		}
		
	}

void daying(char arr1[MAX_CHANG+2][MAX_KUAN+2]){
	for (int c = 0; c < MAX_CHANG+1; c++){
		printf(" %d ", c);//�к�
	}
	printf("\n");
	for (int i = 1; i <= MAX_CHANG; i++){
		printf("%02d|", i);
		for (int j = 1; j <= MAX_KUAN; j++){
			printf(" %c ", arr1[i][j]);
		}
		
		printf("\n");
		printf("\n");
	}
}
void game(){
	int count = 0;
	char arr1[MAX_CHANG + 2][MAX_KUAN + 2];
	char arr2[MAX_CHANG + 2][MAX_KUAN + 2];
	usermap(arr1, arr2);
	while (1){
		if (count == MAX_CHANG*MAX_KUAN - boom){
			printf("��Ӯ��!!!!\n");
			break;
		}
		else{
			int a, b;
			daying(arr1);
			printf("������Ҫɨ���׵�����\n");
			scanf("%d %d", &b, &a);
			if (a > MAX_CHANG || b > MAX_CHANG || a < 0 || b < 0){
				printf("�Ƿ�������ֵ\n");
			}
			else if (arr2[a][b] == '1'){
				printf("�����ˣ�\n");
				break;
			}
			
			else {
				chuli(arr1, arr2, a, b); 
			}
			
		}
	}
}

void start(){
	while (1){
		int choice = menu();
		if (choice == 1){//�˳�
			break;
		}
		else if (choice == 0){
			game();
		}
		else{
			printf("��ѡ��1����2!!!!!!!!!!!!!!!\n");
		}
	}
}


int menu(){
	printf("****************************************\n");
	printf("1.��ʼ��Ϸ\n");
	printf("2.������Ϸ\n");
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