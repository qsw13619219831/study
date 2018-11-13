#include<stdio.h>
#include<math.h>
int main(){
	int n = 6;
	int c = 0;
	for (int i = n-1; i >0; i--){
		c = i*n;
		n = c;
	}
	printf("%d", n);
	system("pause");
}