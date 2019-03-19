#pragma once

typedef int SLDataType;
typedef struct SeqList{
	SLDataType* arry;
	int capacity;
	int size;
	
}SeqList;
void SeqListInit(SeqList*seqlist, int a);

void SeqListDestroy(SeqList*seqlist);

void SeqListPushBack(SeqList*seqlist);

void SeqListPushFront(SeqList*seqlist);

void SeqListInsert(SeqList *seqlist, int pop);

void SeqListPopback(SeqList*seqlist);

void SeqListPopFront(SeqList*seqlist);

void SeqListErase(SeqList*seqlist, int pop);

int SeqListFind(SeqList*seqlist, SLDataType v);
	
void SeqListPrint(SeqList*seqlist);

void SeqListRemove(SeqList*seqlist, SLDataType v);

void SeqListRemoveAll(SeqList*seqlist, SLDataType v);

void SeqListModify(SeqList*seqlist, int pos, SLDataType v);
