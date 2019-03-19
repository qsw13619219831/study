#include"SeqList.h"

void Test2() {
	SeqList seqlist;
	SeqListInit(&seqlist, 10);
	SeqListPushBack(&seqlist, 5);
	SeqListPushBack(&seqlist, 2);
	SeqListPushBack(&seqlist, 3);
	SeqListPushBack(&seqlist, 3);
	SeqListPushBack(&seqlist, 4);
	SeqListPushBack(&seqlist, 3);
	SeqListPushBack(&seqlist, 3);
	SeqListRemoveAll(&seqlist, 3);
	SeqListPrint(&seqlist);

}
int main() {
	Test2();
	system("pause");
	return 0;
	
}