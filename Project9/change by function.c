#include<stdio.h>
void change(int *x, int *y){
		int mid=0;
		mid = *x;
		*x = *y;
		*y = mid;
}
int main(){
	int a = 5;
	int b = 6;
	change(&a,&b);
	printf("%d,%d", a, b);
	system("pause");
	return 0;
}