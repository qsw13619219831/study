#include<stdio.h>
#include<math.h>
int strlen(char *arr){
	if (*arr != '\0'){
		return strlen(arr + 1)+1 ;
	}
	return 0;
	
}
int main(){
	char arr[] = "abcdef";
	int a =strlen(arr);
	printf("%d", a);
	system("pause");
	return 0;
}