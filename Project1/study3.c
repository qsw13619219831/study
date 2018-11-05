#include <stdio.h>
#include<math.h>
/*打印
* 
***
*****
*******
*********
***********
*************
***********
*********
*******
*****
***
*
*/
int main(){
	int i;
	int n;
	int j;
	int k;
	int count=6;
	//上面一个三角，下面一个三角
	for (i = 0; i < 7; i++){
		for (n = 0; n < 13; n++){
			if (n<count - i || n>count + i){
				printf(" ");
			}
			else
				printf("*");
		}
		printf("\n");
	}
	count++;
	for (j = 6; j >0; j--){
		for (k = 0; k < 13; k++){
			if (k<count - j || k>count + j-2){
				printf(" ");
			}
			else
				printf("*");
		}
		printf("\n");
	}




	system("pause");
	return 0;


}