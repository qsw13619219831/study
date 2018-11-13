#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int function(int x){
	if (x<3){
		return 1;
	}
	return function(x - 1) + function(x - 2);
}
int main(){
	int a = function(6);
	printf("%d", a);
	system("pause");
	return 0;
}