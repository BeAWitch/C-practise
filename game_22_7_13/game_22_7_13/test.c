#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void game()
{
	//储存雷的信息
	char mine[ROWS][COLS] = { 0 };//11*11
	//排查出的雷的信息
	char show[ROWS][COLS] = { 0 };
	//初始化
	initboard(mine, ROWS, COLS, '0');
	initboard(show, ROWS, COLS, '*');
	//打印棋盘
	displayboard(show, ROW, COL);
	//布置地雷
	setmine(mine,ROW,COL);
	//扫雷
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
	printf("请选择（1/2）：");
	scanf("%d", &n);
	switch (n)
	{
	case 1:
		game();
		break;
	case 0:
		printf("退出游戏");
		break;
	default:
		printf("输入错误，请重试");
	}
}
int main()
{
	test();
	return 0;
}