/*给定一个数组，它的第 i 个元素是一支给定股票第 i 
天的价格。设计一个算法来计算你所能获取的最大利润。
你可以尽可能地完成更多的交易（多次买卖一支股票）。
。*/
#include<stdio.h>
#include<math.h>
int main(){
	int arr[] = { 7, 1, 5, 3, 6, 4 };
	int count = 0;
	//贪心算法，从微观上分析不需要注重全局
	int lenth = sizeof arr / sizeof arr[0];
	for (int i = 0; i < lenth; i++){
		if (arr[i + 1]>arr[i]){
			int tem = arr[i + 1] - arr[i];
			count += tem;
		}
	}
	printf("%d", count);
	system("pause");
	return 0;
}