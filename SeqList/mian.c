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
		printf("请选择: >");
		scanf_s("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("输入插入的数据（-1）结尾:");
			while(scanf_s("%d", &Item), Item != -1)
			{
				push_back(&mylist, Item);
			}

			break;
		case 2:
			printf("输入首插的数据（-1）结尾：");
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
			printf("输入插入的数据：");
			scanf_s("%d", &Item);
			printf("请输入要插入的位置：");
			scanf_s("%d", &pos);
			insert_pos(&mylist, Item, pos);
			break;
		case 7:
			printf("输入要查找的数据：");
			scanf_s("%d", &Item);
			pos = find(&mylist, Item);
			if (-1 == pos)
			{
				printf("查找的数据%d在顺序表中不存在\n", Item);
			}
			else
			{
				printf("查找的数据%d在顺序表的位置为%d", Item, pos);
			}
			break;
		case 8 :
			printf("顺序表的长度为%d\n", length(&mylist));
			break;
		case 9:
			printf("输入要删除的位置：");
			scanf_s("%d", &pos);
			delete_pos(&mylist, pos);
			break;
		case 10:
			printf("输入要删除的数据：");
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
			printf("输入选择错误，请重新输入:\n");
			break;
		}

	}
}