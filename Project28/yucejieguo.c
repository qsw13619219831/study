#include<stdio.h>
#include<math.h>
int main(){
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	for (a = 1; a < 6; a++){
		for (b = 0; b < 6; b++){
			for (c = 0; c < 6; c++){
				for (d = 0; d < 6;d++){
					for (e = 0; e < 6;e++){
						if ((b==2&&a!=3)||(b!=2&&a==3)){
							if ((b==2&&e!=4) || (b!=2&&e==4)){
								if ((c==1&&d!=2)||(c!=1&&d==2)){
									if ((c==5&&d!=3)||(c!=5&&d==3)){
										if ((e==4&&a!=1)||(e!=4&&a==1)){
											if (a*b*c*d*e==120){
												printf("%d %d %d %d %d", a, b, c, d, e);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}
