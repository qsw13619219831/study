/*����һ�����飬���ĵ� i ��Ԫ����һ֧������Ʊ�� i 
��ļ۸����һ���㷨�����������ܻ�ȡ���������
����Ծ����ܵ���ɸ���Ľ��ף��������һ֧��Ʊ����
��*/
#include<stdio.h>
#include<math.h>
int main(){
	int arr[] = { 7, 1, 5, 3, 6, 4 };
	int count = 0;
	//̰���㷨����΢���Ϸ�������Ҫע��ȫ��
	int lenth = sizeof arr / sizeof arr[0];
	for (int i = 0; i < lenth; i++){
		if (arr[i + 1]>arr[i]){
			int tem = arr[i + 1] - arr[i];
			count += tem;
		}
	}
	printf("%d", count);
	system("pause");
	return 0;
}