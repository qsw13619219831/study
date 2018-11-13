#include<stdio.h>
#include<math.h>
int fun(int x){
	if (x == 1){
		return 1;
	}
	return fun(x - 1)*x;
}
int main(){
	int a = 6;
	int b=fun(6);
	printf("%d", b);
	system("pause");
	return 0;
}