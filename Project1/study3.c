#include <stdio.h>
#include<math.h>
//求水仙花 数
int main(){
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < 9; i++){
		for (j = 0; j < 9;j++){
			for (k = 0; k < 9;k++){
				if (pow(i, 3) + pow(j, 3) + pow(k, 3) == i * 100 + j * 10 + k){
					printf("%d\n", i * 100 + j * 10 + k);
				}
			}
		}
	}


	system("pause");
	return 0;


}