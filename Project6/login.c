//���������½
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int i;
	char str_1[] = "123456";
	char str_2[5];
	for (i = 0; i < 3;i++){
		printf("�������������\n");
		scanf("%s", &str_2);
		if (strcmp(str_1,str_2)==0){
			printf("��ȷ\n");
			break;
			
		}
		else
			printf("����\n");
	}

	if (i == 3){
		printf("�������δ��󣬰�������˳�\n");
	}
	system("pause");
		return 0;
	
}