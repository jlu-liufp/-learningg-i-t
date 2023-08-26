
#ifndef __SEQLIST__
#define __SEQLIST__

#include<stdio.h>
#include<assert.h>

#define SEQLIST_INIT_SIZE 8
typedef int ElemType;

typedef struct SeqList_
{

	ElemType *base;
	int capacity;
	int size;
}SeqList;

void InitSeqList(SeqList* list);

void push_back(SeqList* list, ElemType x);

void show_list(SeqList* list);

void push_front(SeqList* list,ElemType Item);

void pop_back(SeqList* list, ElemType Item);

void pop_front(SeqList* list, ElemType Item);

void insert_pos(SeqList* list, ElemType Item, ElemType pos);

ElemType find(SeqList* list, ElemType Item);

ElemType length(SeqList* list);

void delete_pos(SeqList* list, ElemType pos);

void delete_val(SeqList* list, ElemType Item);

void sort(SeqList* list);

void reverse(SeqList* list);

void clear(SeqList* list);

void destroy(SeqList* list);

#endif




