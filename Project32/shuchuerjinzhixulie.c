#include<stdio.h>
#include<stdlib.h>

void quchuwei( int value, int arr[32]){
	
	for (int i = 0; i < 32; i++){
		if (i % 2 == 0){
			if (value % 2 == 1){
				arr[i] = 1;
			}
			else{
				arr[i] = 0;
			}
				value >>= 1;
		}
		else{
			if (value % 2 == 1){
				arr[i] = 1;
			}
			else{
				arr[i] = 0;
			}
			value >>= 1;
		}
	}
}
int main(){
	int arr[32];
	for (int i = 0; i < 32; i++){
		arr[i] = 0;
	}
	quchuwei(111, arr);
	printf("偶数的：\n");
	for (int i = 31; i >=0; i--){
		if (i%2==0)
		printf("%d", arr[i]);
	}
	printf("\n");
	printf("奇数的：\n");
	for (int i = 31; i >= 0; i--){
		if (i%2!=0)
		printf("%d", arr[i]);
	}

	system("pause");
	return 0;
}