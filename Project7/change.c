#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main(){
	for (;;){
		char in = 0;
		scanf("%c", &in);
		if (in >= 'a'&&in <= 'z'){
			in = in - 32;
			printf("%c", in);
			}
		else if (in >= 'A'&&in <= 'Z'){
			in = in + 32;
			printf("%c", in);
			}
		
	}
	system("pause");
	return 0;
}