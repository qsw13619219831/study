#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main(){
	int n;
	int a;
	int last;
	int next;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		if (i<2){
			last = 1;
			next = 1;
			if (n == i){
				printf("%d\n", next);
			}
		}
		else{
			a=last;
			last = next;
			next = a+ next;
				printf("%d\n", next);
			}
		}
	

	system("pause");
	return 0;
}