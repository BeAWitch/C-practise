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
	//����ͨѶ¼ 
	struct contact con;//con����ͨѶ¼��������1000�������size
	//��ʼ��ͨѶ¼
	initcontact(&con);

	do
	{
		menu();
		printf("��ѡ��");
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
			showcontact(&con);//����ַ�����ܸ��ã����ÿ����ṹ��
			break;
		case sort:
			break;
		case exit:
			break;
		default:                       
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}