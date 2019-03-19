#include"SeqList.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//³õÊ¼»¯
void SeqListInit(SeqList*seqlist,int a){
	assert(seqlist != NULL);
	seqlist->capacity =  a;
	seqlist->arry = (SLDataType*)malloc(sizeof(SLDataType)*seqlist->capacity);
	seqlist->size = 0;


}

void SeqListDestroy(SeqList*seqlist){
	assert(seqlist != NULL);
	assert(seqlist->arry != NULL);
	free(seqlist->arry);
	seqlist->arry = NULL;
	seqlist->capacity = seqlist->size = 0;
}

void SeqListPushBack(SeqList*seqlist,SLDataType V){
	assert(seqlist != NULL);
	assert(seqlist->arry != NULL);
	seqlist->arry[seqlist->size] = V;
	seqlist->size++;

}

void SeqListPushFront(SeqList*seqlist,SLDataType v){
	assert(seqlist != NULL);
	assert(seqlist->arry != NULL);
	for (int i = seqlist->size; i > 0; i--){
		seqlist->arry[i] = seqlist->arry[i-1];
	}
	seqlist->size++;
}

void SeqListInsert(SeqList *seqlist, int pop,SLDataType	v){
	assert(seqlist != NULL);
	assert(seqlist->arry != NULL);
	for (int i = seqlist->size; i > pop; i--){
		seqlist->arry[i] = seqlist->arry[i - 1];
		seqlist->arry[pop] = v;
}
	seqlist->size++;
}

void SeqListPopback(SeqList*seqlist){
	assert(seqlist != NULL);
	assert(seqlist->arry != NULL);
	seqlist->size--;

}

void SeqListPopFront(SeqList*seqlist){
	assert(seqlist != NULL);
	assert(seqlist->arry != NULL);
	for (int i = 0; i < seqlist->size - 1; i++){
		seqlist->arry[i] = seqlist->arry[i + 1];
	}
	seqlist->size--;

}

void SeqListErase(SeqList*seqlist, int pop){
	assert(seqlist != NULL);
	assert(seqlist->arry != NULL);
	for (int i = pop; i < seqlist->size - 1; i++){
		seqlist->arry[i] = seqlist->arry[i + 1];
	}
	seqlist->size--;
}

int SeqListFind(SeqList*seqlist, SLDataType v){
	assert(seqlist != NULL);
	assert(seqlist->arry != NULL);
	for (int i = 0; i < seqlist->size; i++){
		if (seqlist->arry[i] == v){
			return i;
		}
}
	return -1;
}

void SeqListPrint(const SeqList*seqlist){
	assert(seqlist != NULL);
	assert(seqlist->arry != NULL);
	for (int i = 0; i < seqlist->size; i++){
		printf("%d\n", seqlist->arry[i]);
	}
}

void SeqListRemove(SeqList*seqlist, SLDataType v){
	assert(seqlist != NULL);
	assert(seqlist->arry != NULL);
	for (int i = 0; i < seqlist->size; i++){
		if (seqlist->arry[i] = v){
			return i;
		}
	}
	return -1;
}

void SeqListRemoveAll(SeqList*seqlist, SLDataType v){
	assert(seqlist != NULL);
	assert(seqlist->arry != NULL);
	int i = 0, j = 0;
	for (; i < seqlist->size; i++){
		if (seqlist->arry[i] != v){
			seqlist->arry[j] = seqlist->arry[i];
			j++;
		}
	}
	seqlist->size = j;
}

void SeqListModify(SeqList*seqlist, int pos, SLDataType v){
	assert(seqlist != NULL);
	assert(seqlist->arry != NULL);
	seqlist->arry[pos] = v;
}
