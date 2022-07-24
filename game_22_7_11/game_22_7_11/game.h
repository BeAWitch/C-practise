#pragma once

#define ROW 3//行
#define COL 3//列

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void initboard(char board[ROW][COL],int row,int col);
void displayboard(char board[ROW][COL], int row, int col);
void playermove(char board[ROW][COL], int row, int col);
void computermove(char board[ROW][COL], int row, int col);

//玩家赢--*
//电脑赢--#
//平局--p
//继续--c
char iswin(char board[ROW][COL], int row, int col);