#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void initcontact(struct contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;
}

void addcontact(struct contact* ps) 
{
	if (MAX == ps->size)
	{
		printf("通讯录已满");
	}
	else
	{
		printf("请输入名字：");
		scanf("%s", ps->data[ps -> size].name);
		printf("请输入年龄：");
		scanf("%d", &(ps->data[ps->size].age));
		printf("请输入性别：");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入电话：");
		scanf("%s", ps->data[ps->size].tale);
		printf("请输入住址：");
		scanf("%s", ps->data[ps->size].addr);
		ps->size++;
		printf("添加成功\n");
	}
}

void showcontact(struct contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tale,
				ps->data[i].addr
			);
		}
	}
}

static findbyname(struct contact* ps, char name[MAX_NAME])//加了static，该函数只能在当前源文件中使用
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;
		}
	}
	return -1;
}
void delcontact(struct contact* ps)
{
	char name[MAX_NAME];
	printf("请选择要删除人的名字：");
	scanf("%s", name);
	//1.查找
	int pos = findbyname(ps, name);
	if (pos == -1)
	{
		printf("要删除的人不存在");
	}
	//2.删除
	else
	{
		int j = 0;
		for (j = pos; j < ps->size-1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功");
	}
}

void searchcontact(struct contact* ps)
{
	char name[MAX_NAME];
	printf("请选择要查找的人的名字：");
	scanf("%s", name);
	int pos = findbyname(ps, name);
	if (pos == -1)
	{
		printf("要查找的人不存在");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[pos].name,
				ps->data[pos].age,
				ps->data[pos].sex,
				ps->data[pos].tale,
				ps->data[pos].addr
			    );
	}
}

void modifycontact(struct contact* ps)
{
	char name[MAX_NAME];
	printf("请选择要查找的人的名字：");
	scanf("%s", name);
	int pos = findbyname(ps, name);
	if (pos == -1)
	{
		printf("要修改的人不存在");
	}
	else
	{
		printf("请输入名字：");
		scanf("%s", ps->data[pos].name);
		printf("请输入年龄：");
		scanf("%d", &(ps->data[pos].age));
		printf("请输入性别：");
		scanf("%s", ps->data[pos].sex);
		printf("请输入电话：");
		scanf("%s", ps->data[pos].tale);
		printf("请输入住址：");
		scanf("%s", ps->data[pos].addr);
		printf("修改成功\n");
	}
}