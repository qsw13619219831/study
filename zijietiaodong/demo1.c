/*�������� nums = [1,1,2], 

����Ӧ�÷����µĳ��� 2, ����ԭ���� nums ��ǰ����Ԫ�ر��޸�Ϊ 1, 2�� 

�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�*/
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
//����δ��ɣ�û��ʵ��ɾ��Ԫ��0