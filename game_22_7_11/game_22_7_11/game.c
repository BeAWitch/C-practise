#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void initboard(char board[ROW][COL], int row, int col)
{
	int i,j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			board[i][j] = ' ';
	}
}
void displayboard(char board[ROW][COL], int row, int col)
{
	int i, j = 0;
	for (i = 0; i < row-1; i++)
	{
		for (j = 0; j < col - 1; j++)
		{
			printf(" %c |", board[i][j]);
		}
		printf(" %c \n", board[i][j]);
		//�ָ���
		for (j = 0; j < col - 1; j++)
		{
			printf("---|");
		}
		printf("---\n");
	}
	//���һ��
	for (j = 0; j < col - 1; j++)
	{
		printf(" %c |", board[i][j]);
	}
	printf(" %c \n", board[i][j]);
}
void playermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�����\n");
	printf("����������(��,��)��");
	//�ж�����Ϸ���
	while (1)
	{
		scanf("%d,%d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (board[x - 1][y - 1] = ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("�����ѱ�ռ��");
		}
		else
		{
			printf("��������,��������������");
		}
	}
}
void computermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("������\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '#';
				break;
			}
		}
	}
}
int isfull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//��3
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][2] == board[i][1] && board[i][0] !=' ')
		{
			return board[i][0];
		}
	}
	//��3
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	//�Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
	{
		return board[0][2];
	}
	//ƽ��
	if (1 == isfull(board,row,col))
		return 'p';
	return 'c';
}