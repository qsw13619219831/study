#include<stdio.h>
#include<stdlib.h>

//дһ���������ز����������� 1 �ĸ��� 
//���磺 15 0000 1111 4 �� 1 
//����ԭ�ͣ� 
//int count_one_bits(unsigned int value) 
//{ 
// // ���� 1��λ�� 
//} 
int count_one_bits(unsigned int value){
	int count=0;
	for (int i = 0; i < 32;i++){
		if (value%2==1){
			count++;
			value >>= 1;
		}
		else{
			value >>= 1;
		}
	}
	return count;

}
int main(){
	int a = count_one_bits(999999);
	printf("%d",a);
	system("pause");
	return 0;
}
