/*给定数组 nums = [1,1,2], 

函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。 

你不需要考虑数组中超出新长度后面的元素。*/
#include<stdio.h>
#include<math.h>
int main(){
	int nums[] = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
	for (int i = 0; i < 10; i++){
		for (int j = i + 1; j < 10; j++){
			if (nums[i] == nums[j]){
				nums[i] = 0;
			}
		}
	}
	for (int i = 0; i < 10;i++){
		for (int j = 0; j < 10; j++){
			if (nums[j] < nums[j + 1]){
				int count = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = count;
			}
		}
	}
	for (int i = 0; i < 10; i++){
		printf("%d", nums[i]);
	}
	system("pause");
	return 0;
}
//功能未完成，没有实现删除元素0