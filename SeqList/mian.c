#include"SeqList.h"
#define _CRT_SECURE_NO_WARNINGS
void main(void)
{
	SeqList mylist;
	InitSeqList(&mylist);
	int select = 1;
	ElemType  Item;
	ElemType  pos;
	while (select)
	{
		printf("********************************\n");
		printf("* [1] push_back  [2] push_front*\n");
		printf("* [3] show_list  [4] pop_back  *\n");
		printf("* [5] pop_front  [6] insert_pos*\n");
		printf("* [7] find       [8] length    *\n");
		printf("* [9] delete_pos [10]delete_val*\n");
		printf("* [11] sort      [12] reverse  *\n");
		printf("* [13] clear     [14] destroy  *\n");
		printf("* [0] quit_system             *\n");
		printf("*********************************");
		printf("��ѡ��: >");
		scanf_s("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("�����������ݣ�-1����β:");
			while(scanf_s("%d", &Item), Item != -1)
			{
				push_back(&mylist, Item);
			}

			break;
		case 2:
			printf("�����ײ�����ݣ�-1����β��");
			while (scanf_s("%d", &Item), Item != -1)
			{
				push_front(&mylist, Item);
			}
			break;
		case 3:
			show_list(&mylist);
			break;
		case 4:
			pop_back(&mylist, Item);
			break;
		case 5:
			pop_front(&mylist, Item);
			break;
		case 6:
			printf("�����������ݣ�");
			scanf_s("%d", &Item);
			printf("������Ҫ�����λ�ã�");
			scanf_s("%d", &pos);
			insert_pos(&mylist, Item, pos);
			break;
		case 7:
			printf("����Ҫ���ҵ����ݣ�");
			scanf_s("%d", &Item);
			pos = find(&mylist, Item);
			if (-1 == pos)
			{
				printf("���ҵ�����%d��˳����в�����\n", Item);
			}
			else
			{
				printf("���ҵ�����%d��˳����λ��Ϊ%d", Item, pos);
			}
			break;
		case 8 :
			printf("˳���ĳ���Ϊ%d\n", length(&mylist));
			break;
		case 9:
			printf("����Ҫɾ����λ�ã�");
			scanf_s("%d", &pos);
			delete_pos(&mylist, pos);
			break;
		case 10:
			printf("����Ҫɾ�������ݣ�");
			scanf_s("%d", &Item);
			delete_val(&mylist, Item);
			break;
		case 11:
			sort(&mylist);
			break;
		case 12 :
			reverse(&mylist);
			break;
		case 13:
			clear(&mylist);
			break;
		case 14:
			destroy(&mylist);
			break;
		default:
			printf("����ѡ���������������:\n");
			break;
		}

	}
}