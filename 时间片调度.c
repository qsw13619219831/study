//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<stdbool.h>
//
//#define slice 2//����ʱ��Ƭ
//
//typedef struct pcb {
//	char name[10];//������
//	int reqtime;//Ҫ�����ʱ��
//	int runtime;//����ʱ��
//	int arrtime;//����ʱ��
//	char status;//״̬
//}PCB;
//int intarr = 0, intfin = 0;//������̸�������ɽ��̸���
//PCB pcbarr[24] ;
//PCB pcbrun[24];//����pcb
//
//int RunTime = 0;
//int ready = 1;
//
//void Input() {
//	int i;
//	int n=0;
//	printf("��������̸���;");
//	scanf("%d", &intarr);
//	for (i = 0; i<intarr; i++) {
//		//pcbarr[intarr].arrivetime = i + 1;
//		printf("\n��%d������:\n�����������:", i+1 );
//		scanf("%s", pcbarr[i].name);
//		printf("�����뵽��ʱ��:");
//		scanf("%d", &pcbarr[i].arrtime);
//		printf("������Ҫ�����ʱ��:");
//		scanf("%d", &pcbarr[i].reqtime);
//		if (i == 0)
//			pcbarr[i].status =' r';
//		else
//			pcbarr[i].status = 'w';
//	}
//}
//
//void Output() {
//	int i = 0;
//	printf("\n");
//	printf("\tname\tarrtime\treqtime\truntime\tstatus\n");
//	for (i = 0; i<intarr; i++)
//		printf("N%d\t%s\t%d\t%d\t%d\t%c\n", i, pcbrun[i].name, pcbrun[i].arrtime, pcbrun[i].reqtime, pcbrun[i].runtime,pcbrun[i].status);
//}
//
//void running() {
//	int i ;
//	for(i=1;i<intarr;i++){
//		if (pcbarr[i].arrtime <= RunTime + slice&&pcbarr[i].status=='w') {
//			pcbrun[i] = pcbarr[i];
//			pcbarr[i].status = 'r';
//			pcbrun[i].status = 'r';
//			ready++;
//		}
//	}
//	for ( i = 0; i < ready; i++) {
//		if (pcbarr[i].status == 'f') {
//			//ready--;
//		}else {
//			pcbrun[i].reqtime = pcbrun[i].reqtime-slice;
//			RunTime += slice;
//			pcbrun[i].runtime = RunTime;
//			if (pcbrun[i].reqtime <= 0) {
//				pcbarr[i].status = 'f';
//				pcbrun[i].status = 'f';
//			}
//		}		
//	}
//}
//
//void Sort() {//������ʱ������
//	int i, j;
//	PCB temp;
//	for (i = 0; i < intarr - 1; i++) {
//		for (j = i + 1; j < intarr; j++) {
//			if (pcbarr[i].arrtime > pcbarr[j].arrtime) {
//				temp = pcbarr[i];
//				pcbarr[i] = pcbarr[j];
//				pcbarr[j] = temp;
//			}
//		}
//	}
//	pcbarr[0].status = 'r';
//	for (i = 1; i < intarr; i++)
//		pcbarr[i].status = 'w';
//}
//
//bool judge() {
//	int sum = 0;
//	for (int i = 0; i < intarr; i++) {
//		if (pcbarr[i].status == 'f')
//			sum++;
//	 }
//	if (sum == intarr)
//		return false;
//	else
//		return true;
//}
//
//void main() {
//	Input();
//	printf("\n��ʼ״̬Ϊ:\n");
//	//Output();
//	printf("\tname\tarrtime\treqtime\truntime\tstatus\n");
//	for (int i = 0; i<intarr; i++)
//		//printf("N%d\t%s\t%d\t%d\t%d\t%c\n", i, pcbfin[i].name, pcbfin[i].reatime, pcbfin[i].reqtime, pcbfin[i].runtime);
//		printf("N%d\t%s\t%d\t%d\t%d\t%c\n", i, pcbarr[i].name, pcbarr[i].arrtime, pcbarr[i].reqtime, pcbarr[i].runtime, pcbarr[i].status);
//	Sort();
//	printf("\n����˳��Ϊ:\n");
//	printf("\tname\tarrtime\treqtime\truntime\tstatus\n");
//	for (int i = 0; i<intarr; i++)
//		printf("N%d\t%s\t%d\t%d\t%d\t%c\n", i, pcbarr[i].name, pcbarr[i].arrtime, pcbarr[i].reqtime, pcbarr[i].runtime, pcbarr[i].status);
//	pcbrun[0] = pcbarr[0];
//	while (judge()) {
//		running();
//		Output();
//	}
//	system("pause");
//}