#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define N 50
struct PCB
{
	int pn;   //process name��������
	int at;   //arrival time����ʱ��
	int st;   //service time����ʱ��
	int ct;   //completion time���ʱ��
	int sc;  //sign completion��־�Ƿ����
	int st1;  //ʣ�����ʱ��  
}process[N];

int sjp(int n)
{
	int i, j, T;
	printf("\n������ʱ��Ƭ��\n");
	scanf("%d", &T);
	for (i = 1; i <= n; i++)      //�ռ�������Ϣ 
	{
		process[i].sc = 0;
		printf("\n%d:\n������������̵���Ϣ\n������pn:", i);
		scanf("%d", &process[i].pn);
		printf("������at:");
		scanf("%d", &process[i].at);
		printf("������st:");
		scanf("%d", &process[i].st);
		process[i].st1 = process[i].st;
	}
	for (i = 1; i <= n; i++)
	for (j = i + 1; j <= n; j++)   //���ո����̵���ʱ�����򣬶Խ������� ע�⣺�ȶ������� 
	{
		if (process[j].at<process[i].at)
		{
			process[0] = process[j];
			process[j] = process[i];
			process[i] = process[0];
		}
	}
	//for(i=1;i<=n;i++)    //��������Ƿ���ȷ
	//printf("%d\t",process[i].pn);

	int time = process[1].at;      //��ǰʱ��ĳ�ֵ 
	int flag = 1;
	int sum = 0;					//��¼��ɵĽ����� 
	printf("\n�ڼ��ε��Ƚ��� ���еĽ���pn ��ʼ����ʱ�� ����ʱ�� ʣ�����ʱ�� ����ʱ��\n");
	int z = 1;   //��¼�ڼ��ε��Ƚ��� 

	while (sum<n)
	{
		flag = 0;	     //��־�����������Ƿ��н��� 
		for (i = 1; i <= n; i++)    //ʱ��Ƭ��ת��ִ�и����� 
		{
			if (process[i].sc == 1) continue;  //����ɵĽ��� 
			else
			{
				if (process[i].st1 <= T&&time >= process[i].at)//δ��ɵĽ��̵��ǻ�������ʱ�����ڵ���һ��ʱ��Ƭ 
				{
					flag = 1;
					time = time + process[i].st1;
					process[i].sc = 1;
					process[i].ct = time;
					printf("%8d%12d%15d%11d%11d%11d\n", z++, process[i].pn, time - process[i].st1, process[i].st1, 0, time);
					process[i].st1 = 0;
				}

				else if (process[i].st1>T&&time >= process[i].at)//δ��ɵĽ��̵��仹�����ʱ�����ٴ���һ��ʱ��Ƭ 
				{
					flag = 1;
					time = time + T;
					process[i].st1 -= T;
					printf("%8d%12d%15d%11d%11d%11d\n", z++, process[i].pn, time - T, T, process[i].st1, time);
				}
				if (process[i].sc == 1) sum++;     //һ������ִ�����+1 
			}
		}

		if (flag == 0 && sum<n)   // ����ûִ�еĽ��̣���û����;������� 
		{
			for (i = 1; i <= n; i++)
			if (process[i].sc == 0) { time = process[i].at; break; }
		}
	}
}

int main()
{
	int n;
	printf("\t\tʱ��Ƭ��ת�����㷨\n");
	printf("�������ܽ�������\n");
	scanf("%d", &n);
	sjp(n);
	system("pause");
	return 0;
}
