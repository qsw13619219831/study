//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<stdbool.h>
//
//#define slice 2//定义时间片
//
//typedef struct pcb {
//	char name[10];//进程名
//	int reqtime;//要求服务时间
//	int runtime;//运行时间
//	int arrtime;//到达时间
//	char status;//状态
//}PCB;
//int intarr = 0, intfin = 0;//到达进程个数，完成进程个数
//PCB pcbarr[24] ;
//PCB pcbrun[24];//运行pcb
//
//int RunTime = 0;
//int ready = 1;
//
//void Input() {
//	int i;
//	int n=0;
//	printf("请输入进程个数;");
//	scanf("%d", &intarr);
//	for (i = 0; i<intarr; i++) {
//		//pcbarr[intarr].arrivetime = i + 1;
//		printf("\n第%d个进程:\n请输入进程名:", i+1 );
//		scanf("%s", pcbarr[i].name);
//		printf("请输入到达时间:");
//		scanf("%d", &pcbarr[i].arrtime);
//		printf("请输入要求服务时间:");
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
//void Sort() {//按到达时间排序
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
//	printf("\n初始状态为:\n");
//	//Output();
//	printf("\tname\tarrtime\treqtime\truntime\tstatus\n");
//	for (int i = 0; i<intarr; i++)
//		//printf("N%d\t%s\t%d\t%d\t%d\t%c\n", i, pcbfin[i].name, pcbfin[i].reatime, pcbfin[i].reqtime, pcbfin[i].runtime);
//		printf("N%d\t%s\t%d\t%d\t%d\t%c\n", i, pcbarr[i].name, pcbarr[i].arrtime, pcbarr[i].reqtime, pcbarr[i].runtime, pcbarr[i].status);
//	Sort();
//	printf("\n到达顺序为:\n");
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