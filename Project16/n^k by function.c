#include<stdio.h>
#include<math.h>
int power(int x,int y){
	if (y==0){
		return 1;
	}
	if (y==1){
		return x;
	}
	return power(x, y - 1)*x;
}
int main(){
	int a = power(2, 10);
	printf("%d",a);
	system("pause");
	return 0;
}