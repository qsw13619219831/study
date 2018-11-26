#include<stdio.h>
#include<stdlib.h>

//写一个函数返回参数二进制中 1 的个数 
//比如： 15 0000 1111 4 个 1 
//程序原型： 
//int count_one_bits(unsigned int value) 
//{ 
// // 返回 1的位数 
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
