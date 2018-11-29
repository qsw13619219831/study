#include<stdio.h>
#include<stdlib.h>
void reserve(char* left,char* right){
	while(left < right){
		int tem = *right;
		*right = *left;
		*left = tem;
		left++;
		right--;
	}
}
void change(char arr[]){
	char* end=0;
	char* start = arr;
	while (*arr != '\0'){
		if (*arr == ' '){
			end = arr - 1;
			reserve(start, end);
			start = end+2;
			end = 0;
			arr++;
		}
		else{
			arr++;
		}
	}
}

int main(){
	char arr[] = " student a am i";
	int a = (sizeof arr / sizeof arr[0])-2;
	reserve(arr, arr + a);
	change(arr);

	
	
	for (int i = 0; i <= a; i++){
		printf("%c", arr[i]);
	}
	system("pause");
	return 0;
}