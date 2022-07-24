#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"


void game()
{
	char ret = 'a';
	//创建棋盘
	char board[ROW][COL]={0};
	//初始化棋盘
	initboard(board, ROW, COL);
	//打印棋盘,全部空格
	displayboard(board, ROW, COL);
	while (1)
	{
		//玩家下棋
		playermove(board, ROW, COL);
		displayboard(board, ROW, COL);
		//判断玩家是否获胜
		ret=iswin(board,ROW,COL);
		if (ret != 'c')
		{
			break;
		}
		//电脑下棋
		computermove(board, ROW, COL);
		displayboard(board, ROW, COL);
		//判断电脑是否获胜
		ret = iswin(board, ROW, COL);
		if (ret !='c')
		{
			break;
		}
	}
	if (ret == '*')
		printf("玩家赢");
	else if (ret == '#')
		printf("电脑赢");
	else if (ret == 'p')
		printf("平局");
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
	printf("请选择(1/2):");
	scanf("%d", &input);
	switch(input)
	{
		case 1:
			game();
			break;
		case 2:
			printf("退出游戏");
			break;
		default:
			printf("请重新选择\n");
			break;
	}

}
int main()
{
	test();
	return 0;
}