#include<stdio.h>
int compare(int x,int y){
	int c = x^y;
	int count = 0;
	for (int i = 0; i < 32; i++){
		if (c % 2 == 1){
			count++;
			c >>= 1;
		}
		else{
			c >>= 1;
		}
	}
	return count;
	}

int main(){
	
	int d = compare(1999, 2299);
	printf("%d", d);
	system("pause");
	return 0;
}