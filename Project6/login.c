//输入密码登陆
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
		printf("请输入你的密码\n");
		scanf("%s", &str_2);
		if (strcmp(str_1,str_2)==0){
			printf("正确\n");
			break;
			
		}
		else
			printf("错误\n");
	}

	if (i == 3){
		printf("输入三次错误，按任意键退出\n");
	}
	system("pause");
		return 0;
	
}