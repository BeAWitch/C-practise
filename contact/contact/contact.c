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
		printf("ͨѶ¼����");
	}
	else
	{
		printf("���������֣�");
		scanf("%s", ps->data[ps -> size].name);
		printf("���������䣺");
		scanf("%d", &(ps->data[ps->size].age));
		printf("�������Ա�");
		scanf("%s", ps->data[ps->size].sex);
		printf("������绰��");
		scanf("%s", ps->data[ps->size].tale);
		printf("������סַ��");
		scanf("%s", ps->data[ps->size].addr);
		ps->size++;
		printf("��ӳɹ�\n");
	}
}

void showcontact(struct contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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

static findbyname(struct contact* ps, char name[MAX_NAME])//����static���ú���ֻ���ڵ�ǰԴ�ļ���ʹ��
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
	printf("��ѡ��Ҫɾ���˵����֣�");
	scanf("%s", name);
	//1.����
	int pos = findbyname(ps, name);
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����");
	}
	//2.ɾ��
	else
	{
		int j = 0;
		for (j = pos; j < ps->size-1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�");
	}
}

void searchcontact(struct contact* ps)
{
	char name[MAX_NAME];
	printf("��ѡ��Ҫ���ҵ��˵����֣�");
	scanf("%s", name);
	int pos = findbyname(ps, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲�����");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
	printf("��ѡ��Ҫ���ҵ��˵����֣�");
	scanf("%s", name);
	int pos = findbyname(ps, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ��˲�����");
	}
	else
	{
		printf("���������֣�");
		scanf("%s", ps->data[pos].name);
		printf("���������䣺");
		scanf("%d", &(ps->data[pos].age));
		printf("�������Ա�");
		scanf("%s", ps->data[pos].sex);
		printf("������绰��");
		scanf("%s", ps->data[pos].tale);
		printf("������סַ��");
		scanf("%s", ps->data[pos].addr);
		printf("�޸ĳɹ�\n");
	}
}