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
		printf("1.��ʼ��Ϸ\t");
		printf("2.������Ϸ\n");
		scanf("%d", &a);
		switch (a){
		case 1:

			for (;;){
				printf("������һ����Ҫ�µ���\t");
				scanf("%d", &b);
				if (b < c){
					printf("С��\n");

				}
				else if (b>c){
					printf("����\n");

				}
				else{
					printf("��¶��ˣ�����%d\n", b);
					break;
				}
				
			}
			break;
		case 2:
			exit(0);
			
		}

	}
}
