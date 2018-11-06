#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
int main(){
	int a;
	int b;
	for (;;){
		srand(time(NULL));
		int c = (rand() % 100);
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		printf("1.开始游戏\t");
		printf("2.结束游戏\n");
		scanf("%d", &a);
		switch (a){
		case 1:

			for (;;){
				printf("请输入一个你要猜的数\t");
				scanf("%d", &b);
				if (b < c){
					printf("小了\n");

				}
				else if (b>c){
					printf("大了\n");

				}
				else{
					printf("你猜对了，数是%d\n", b);
					break;
				}
				
			}
			break;
		case 2:
			exit(0);
			
		}

	}
}
