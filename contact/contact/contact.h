#pragma once

#include<stdio.h>
#include<memory.h>
#include<string.h>

#define MAX 1000

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TALE 12
#define MAX_ADDR 30

enum option
{
	exit,
	add,
	del,
	search,
	modify,
	show,
	sort
};

struct peoinfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tale[MAX_TALE];
	char addr[MAX_ADDR];
};

//通讯录类型
struct contact
{
	struct peoinfo data[MAX];//存放一个信息
	int size;//记录当前已经有的元素个数
};

//声明函数
void initcontact(struct contact* ps);
void addcontact(struct contact* ps);
void showcontact(struct contact* ps);
void delcontact(struct contact* ps);
void searchcontact(struct contact* ps);
void modifycontact(struct contact* ps);