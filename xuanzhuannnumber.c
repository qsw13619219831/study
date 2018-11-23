/*Ðý×ªÊý×é*/
#include<stdio.h>
#include<math.h>
#define N 100
int main(){
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 ,8,9,10};
	int lenth = sizeof arr / sizeof arr[0];
	int k = 3;
	int arr2[N];
	for (int i = 0; i < k; i++){
		arr2[i] = arr[lenth - k + i ];
	}
	for (int j = lenth - k ; j>=0; j--){
		arr[j + k] = arr[j];
	}
	for (int m = 0; m < k; m++){
		arr[m] = arr2[m];
	}

	for (int i = 0; i < lenth; i++){
		printf("%d", arr[i]);
	}
	system("pause");
	return 0;
}