#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main(){
		int a;
		scanf("%d", &a);
		int arr[] = { 5,6,45,55,77,88,99,20 };
		int lenth = sizeof(arr) / sizeof(int);
		int left=0;
		int right=lenth;
		int mid;
		for (;;){
			mid = (left + right) / 2;
			if (arr[mid] == a){
				printf("是这个数：%d\n",mid);
				break;
			}
			else if (arr[mid] < a){
				printf("小了，在右边\n");
				left = mid;
			}
			else {
				printf("大了，在左边\n");
				right = mid;
			}
		}
	system("pause");
	return 0;
}