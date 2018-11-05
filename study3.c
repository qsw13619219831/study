#include <stdio.h>
#include<math.h>
int main(){
	char a[2];
	for (int i = 0; i < 101;i++){
		 a []= i;
		if (a[0] == 9){
			printf("%d", i);
		}
		if (a[1]==9){
			printf("%d", i);
		}
	}
	system("pause");
	return 0;

}