#include<stdio.h>
#include<stdlib.h>
int average(int x,int y){
	int c = (x + y) >> 1;
	return c;
}

int main(){
	printf("%d",average(100,4));
	system("pause");
	return 0;
}