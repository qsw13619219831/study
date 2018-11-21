#include<stdio.h>
/*日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个 
嫌疑犯的一个。以下为4个嫌疑犯的供词。 
A说：不是我。 
B说：是C。 
C说：是D。 
D说：C在胡说 
已知3个人说了真话，1个人说的是假话。 
现在请根据这些信息，写一个程序来确定到底谁是凶手。 */
int main(){//1凶手0平民
	int a, b, c, d;
	for (a = 0; a < 2; a++){
		for ( b= 0; b < 2; b++){
			for ( c= 0;  c< 2; c++){
				for ( d= 0;  d< 2; d++){
					if (a == 1&&c==1&&d==1&&d!=1){
						if (a+b+c+d==1){
							printf("a=%d,b=%d,c=%d,d=%d", a, b, c, d);
						}
					}
					if (a != 1 && c != 1 && d == 1 && d != 1){
						if (a + b + c + d == 1){
							printf("a=%d,b=%d,c=%d,d=%d", a, b, c, d);
						}
					}
					if (a != 1 && c == 1 && d != 1 && d != 1){
						if (a + b + c + d == 1){
							printf("a=%d,b=%d,c=%d,d=%d", a, b, c, d);
						}
					}
					if (a != 1 && c == 1 && d == 1 && d == 1){
						if (a + b + c + d == 1){
							printf("a=%d,b=%d,c=%d,d=%d", a, b, c, d);
						}
					}
				
				}
			}
		}
	}
	system("pause");
	return 0;
}

