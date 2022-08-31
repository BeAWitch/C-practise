#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void menu()
{
	printf("**************************************\n");
	printf("******  1.add          2.del    ******\n");
	printf("******  3.search       4.modify ******\n");
	printf("******  5.show         6.sort   ******\n");
	printf("******  0.exit                  ******\n");
	printf("**************************************\n");
}
int main()
{
	int input = 0;
	//创建通讯录 
	struct contact con;//con就是通讯录，包含了1000个数组和size
	//初始化通讯录
	initcontact(&con);

	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case add:
			addcontact(&con);
			break;
		case del:
			delcontact(&con);
			break;                                                     
		case search:
			searchcontact(&con);
			break;
		case modify:
			modifycontact(&con);
			break;
		case show:
			showcontact(&con);//传地址的性能更好，不用拷贝结构体
			break;
		case sort:
			break;
		case exit:
			break;
		default:                       
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}