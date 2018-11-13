#include<stdio.h>
#include<math.h>
void reverse_string(char  arr[])
{
	if (*arr == '\0'){
	}
		
	else
	{
		reverse_string(++arr);  
		printf("%c", *(--arr)); 

	}
}
int main()
{
	char arr[] = "abcdefgh";
	reverse_string(arr);
	system("pause");
	return 0;
}


