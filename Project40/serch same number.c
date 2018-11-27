#include<stdio.h>
#include<stdlib.h>
void search_number(int arr[], int lenth){
	for (int i = 0; i < lenth; i++){
		int count = 0;
		for (int j = 0; j < lenth; j++){
			if (arr[i] ^ arr[j]){
			}
			else{
				count++; 
			}
		}
		if (count==1){
			printf("%d\n", arr[i]);
		}
	}
}
int main(){
	int arr[] = { 1, 1, 2, 2, 3, 3, 4,9,1,5,11, 5, 5, 6, 6, 7, 7 };
	int lenth = sizeof arr / sizeof arr[0];
	search_number(arr, lenth);
	system("pause");
	return 0;
}