#include<stdio.h>
#include<math.h>
int digitsum(int x){
	if (x <10){
		return x;
	}
	return digitsum(x / 10) + x % 10;
}
int main(){
	int a = digitsum(1234);
	printf("%d", a);
	system("pause");
	return 0;
}