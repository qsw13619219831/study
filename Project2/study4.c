//��Sn = a + aa + aaa + aaaa + aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
//���磺2 + 22 + 222 + 2222 + 22222
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main(){
	int  a;
	int b=1;
	int count=0;
	int c=0;
	scanf("%d", &a);
	for (int i = 0; i < 5; i++){
		count +=a*b;
		b = b * 10;
		c += count;
	}
	printf("%d\t", c);
	system("pause");
	return 0;
}