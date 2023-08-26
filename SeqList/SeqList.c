#include"SeqList.h"

void InitSeqList(SeqList* list)
{	
	list->base = NULL;
	list->base = (ElemType*)malloc(sizeof(ElemType) * SEQLIST_INIT_SIZE);
	assert(list->base != NULL);
	list->capacity = SEQLIST_INIT_SIZE;
	list->size = 0;
}

void push_back(SeqList* list, ElemType x)
{
	if (list->size >= list->capacity)
	{
		printf("����\n");	
	}
	else
	{
		
		list->base[list->size] = x;
		list->size++;
	}
}

void show_list(SeqList* list)
{
	for (int i = 0; i < list->size; ++i)
	{
		printf("%d ", list->base[i]);
	}
	printf("\n");
}


void push_front(SeqList* list, ElemType Item)
{
	if (list->size >= list->capacity)
	{
		printf(" ˳����Ѿ����ˣ�����ͷ��");
	}
	else
	{
		for (int i = list->size; i > 0; i--)
		{
			list->base[i] = list->base[i-1];
		}
		//list->base[0] = Item;
		//list->size++;
	}
}

void pop_back(SeqList* list, ElemType Item)
{
	if (list->size <= 0)
	{
		printf(" ˳���Ϊ�� �޷�β��");
	}
	else
	{
		list->size -= 1;
	}
}



void pop_front(SeqList* list, ElemType Item)
{
	if (list->size <= 0)
	{
		printf(" ˳���Ϊ�� �޷�β��");
	}
	else
	{
		for (int i = 0; i < list->size - 1; ++i)
		{
			list->base[i] = list->base[i + 1];
		}
		list->size--;
	}
}

void insert_pos(SeqList* list, ElemType Item, ElemType pos)

{

	if (0 > pos || list->size < pos)
	{
		printf("��������λ�÷Ƿ������ܲ������ݡ�\n");
		return;
	}
	//�ж��ܲ��ܲ�������
	if (list->size >= list->capacity)
	{
		printf("˳��������޷���������\n");
	}
	else
	{
		for (int i = list->size; i > pos; i--)		
		{
			list->base[i] = list->base[i - 1];
		}
		list->size++;
		list->base[pos] = Item;
	}
}

ElemType find(SeqList* list, ElemType Item)
{
	for (int i = 0; i < list->size; ++i)
	{
		if (Item == list->base[i])
		{
			return i;
		}
	}
	return -1; 
}

ElemType length(SeqList* list)
{
	return list->size;
}

void delete_pos(SeqList* list, ElemType pos)
{
	if (pos < 0 || pos >= list->size)
	{
		printf("ɾ�����ݷǷ�");
	}
	else
	{
		for (int i = pos; i < list->size - 1; i++)
		{
			list->base[i] = list->base[i + 1];
		}
		list->size--;
	}
}

void delete_val(SeqList* list, ElemType Item)
{
	int pos_ = find(list, Item);
	if (-1 == pos_)
	{
		printf("Ҫɾ�������ݲ�����\n");
	}
	else
	{
		delete_pos(list, pos_);
	}
}

void sort(SeqList* list)
{
	for (int i = 0; i < list->size; ++i)
	{
		for (int j = 0; j < list->size -1- i; ++j)
		{
			if (list->base[j] > list->base[j + 1])
			{
				ElemType tmp = list->base[j];
				list->base[j] = list->base[j + 1];
				list->base[j + 1] = tmp;
			}
			else{}
		}
	}
}

void reverse(SeqList* list)
{
	int low = 0;
	int high = list->size - 1;
	ElemType tmp;
	/*while (low < high)
	{
		tmp = list->base[low];
		list->base[low] = list->base[high];
		list->base[high] = tmp;
		low++;
		high--;
	}*/
	for (; low < high; low++, high--)
	{
		tmp = list->base[low];
		list->base[low] = list->base[high];
		list->base[high] = tmp;
	}
}

void clear(SeqList* list)
{
	list->size = 0;
}

void destroy(SeqList* list)
{
	free(list->base);
	list->base = NULL;
	list->capacity = 0;
	list->size = 0;
}
