//调整数组使奇数全部都位于偶数前面。
#include<stdio.h>
void change(int arr[],int lenth){
	for (int i = 0; i < lenth;i++){
		for (int j = 0; j < lenth-1; j++){
			if ((*(arr + j)) % 2 == 0){
				int tem = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = tem;
			}
		
		}
	}

}
int main(){
	int arr[] = { 1, 2, 3, 5, 46, 8, 5, 1, 2,5,65,65,5,4,5,5};
	int lenth = sizeof arr / sizeof arr[0];
	change(arr, lenth);
	for (int i = 0; i < lenth;i++){
		printf("%d ",arr[i]);
	}
	system("pause");
	return 0;
}
