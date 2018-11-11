#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
void init(int arr[],int size){
	for (int i = 0; i < size; i++){
		arr[i] = 0;
	}
}
void empty(int arr[], int size){
	for (int i = 0; i < size; i++){
		arr[i] = 0;
	}
}

void reverse(int arr[], int size){
	for (int i = 0; i < size/2;i++){
		size--;
		int trm = arr[i];
		arr[i] = arr[size];
		arr[size] = trm;
		
	}
}

int main(){
	int arr[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	reverse(arr, SIZE);
	for (int i = 0; i <10; i++){
		printf("%d\n", arr[i]);
	}
	system("pause");
	return 0;
}