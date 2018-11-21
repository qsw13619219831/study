#include<stdio.h>
#include<math.h>
#define CHANG 20
#define KUAN 41
void init(int arr[CHANG][KUAN]){
	for (int i = 0; i < CHANG;i++){
		for (int j = 0; j < KUAN; j++){
			arr[i][j] = 0;
		}
	}
}
void daying(int arr[CHANG][KUAN]){
	for (int i = 0; i <CHANG; i++){
		for (int j = 0; j < KUAN; j++){
		printf("%d ",arr[i][j]);
			}
		printf("\n");
	}
		
	}


int main(){
	int arr[CHANG][KUAN];
	init(arr);
	arr[0][KUAN/2] = 1;
	for (int i = 1; i <CHANG; i++){
		for (int j = 0; j < KUAN; j++){
			if (j>KUAN/2-i&&j<KUAN/2+i){
				arr[i][j] = arr[i - 1][j] + arr[i - 1][j + 1];
			}
			}
	}
	daying(arr);
	system("pause");
	return 0;
}