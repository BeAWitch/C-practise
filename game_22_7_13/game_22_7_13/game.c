#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void initboard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			board[i][j] = set;
		}
	}
}

void displayboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	//打印列号
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row ; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void setmine(char board[ROWS][COLS], int row, int col)
{
	int count = easy_count;
	int x = 0;
	int y = 0;
	while (count)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x-1][y]+
	       mine[x-1][y-1]+
	       mine[x][y-1]+
	       mine[x+1][y-1]+
	       mine[x+1][y]+
	       mine[x+1][y+1]+
	       mine[x][y+1]+
	       mine[x-1][y+1]-8*'0';
}
void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - easy_count)
	{
		printf("请输入坐标");
		scanf("%d,%d", &x, &y);
		while (1)
		{
			if (x >= 1 && x <= row && y >= 1 && y <= col)
			{
				if (mine[x][y] == '1')
				{
					printf("游戏失败");
					displayboard(mine, row, col);
					break;
				}
				else
				{
					int count = get_mine_count(mine, x, y);
					show[x][y] = count + '0';
					displayboard(show, row, col);
				}
			}
			else
			{
				printf("坐标非法，请重新输入");
			}
		}
	}
	if (win == row * col - easy_count)
	{
		printf("排雷成功");
		display(mine, row, col);
	}
}