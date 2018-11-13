#include<stdio.h>
#include<math.h>
int main(){
	char arr[] =  "abcdef" ;
	int count=0;
	for (int i=0;;i++){
		if (arr[i]!='\0'){
			count++;
		}
		else{
			printf("%d", count);
			break;
		}
	}
	
	system("pause");
}