#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void game()
{
	//�����׵���Ϣ
	char mine[ROWS][COLS] = { 0 };//11*11
	//�Ų�����׵���Ϣ
	char show[ROWS][COLS] = { 0 };
	//��ʼ��
	initboard(mine, ROWS, COLS, '0');
	initboard(show, ROWS, COLS, '*');
	//��ӡ����
	displayboard(show, ROW, COL);
	//���õ���
	setmine(mine,ROW,COL);
	//ɨ��
	findmine(mine, show, ROW, COL);
}

void menu()
{
	printf("*********************************\n");
	printf("***********  1.play   ***********\n");
	printf("***********  0.exit   ***********\n");
	printf("*********************************\n");
}
void test()
{
	int n = 0;
	srand((unsigned int)time(NULL));
	menu();
	printf("��ѡ��1/2����");
	scanf("%d", &n);
	switch (n)
	{
	case 1:
		game();
		break;
	case 0:
		printf("�˳���Ϸ");
		break;
	default:
		printf("�������������");
	}
}
int main()
{
	test();
	return 0;
}