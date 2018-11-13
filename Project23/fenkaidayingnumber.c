#include<stdio.h>
#include<math.h>
void fun(int x){
	if (x > 10){
		fun(x / 10);
	}
	
	printf("%d\n", x % 10);
}
int main(){
	int x = 1234;
	fun(x);
	system("pause");
	return 0;
}