#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"


void game()
{
	char ret = 'a';
	//��������
	char board[ROW][COL]={0};
	//��ʼ������
	initboard(board, ROW, COL);
	//��ӡ����,ȫ���ո�
	displayboard(board, ROW, COL);
	while (1)
	{
		//�������
		playermove(board, ROW, COL);
		displayboard(board, ROW, COL);
		//�ж�����Ƿ��ʤ
		ret=iswin(board,ROW,COL);
		if (ret != 'c')
		{
			break;
		}
		//��������
		computermove(board, ROW, COL);
		displayboard(board, ROW, COL);
		//�жϵ����Ƿ��ʤ
		ret = iswin(board, ROW, COL);
		if (ret !='c')
		{
			break;
		}
	}
	if (ret == '*')
		printf("���Ӯ");
	else if (ret == '#')
		printf("����Ӯ");
	else if (ret == 'p')
		printf("ƽ��");
}
void menu()
{
	printf("********************************\n");
	printf("****   1.play    2.exit     ****\n");
	printf("********************************\n");
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	menu();
	printf("��ѡ��(1/2):");
	scanf("%d", &input);
	switch(input)
	{
		case 1:
			game();
			break;
		case 2:
			printf("�˳���Ϸ");
			break;
		default:
			printf("������ѡ��\n");
			break;
	}

}
int main()
{
	test();
	return 0;
}