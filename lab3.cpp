// lab3.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>


struct node
{
	char inf[256]; // �������� ����������
	int pr;
	struct node *next; // ������ �� ��������� �������
};

struct node *head = NULL, *last = NULL, *f = NULL;
int dlinna = 0;
void spstore(void), review(void), del(char *name);
char find_el[256];
struct node *find(char *name);
struct node *get_struct(void);
struct node *get_struct(void)
{
	struct node *p = NULL;
	char s[256];
	int t;
	if ((p = (node*)malloc(sizeof(struct node))) == NULL)
	{
		printf("������ ��� ������������� ������\n");
		exit(1);
	}
	printf("������� �������� �������: \n ");
	scanf("%s", s);
	if (*s == 0)
	{
		printf("������ �� ���� �����������\n");
		return NULL;
	}
	strcpy(p->inf, s);
	printf("������� #define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>


struct node
{
	char inf[256]; // �������� ����������
	int pr;
	struct node *next; // ������ �� ��������� �������
};

struct node *head = NULL, *last = NULL, *f = NULL;
int dlinna = 0;
void spstore(void), review(void), del(char *name);
char find_el[256];
struct node *find(char *name);
struct node *get_struct(void);
struct node *get_struct(void)
{
	struct node *p = NULL;
	char s[256];
	int t;
	if ((p = (node*)malloc(sizeof(struct node))) == NULL)
	{
		printf("������ ��� ������������� ������\n");
		exit(1);
	}
	printf("������� �������� �������: \n ");
	scanf("%s", s);
	if (*s == 0)
	{
		printf("������ �� ���� �����������\n");
		return NULL;
	}
	strcpy(p->inf, s);
	printf("������� ���������: \n ");
	scanf("%i", &(p->pr));
	p->next = NULL;
	return p;
}
void spstore(void)
{
	struct node *p = NULL, *temp = head;
	p = get_struct();
	if (head == NULL && p != NULL) // ���� ������ ���, �� ������������� ������
	{
		head = p;
	}
	else if (head != NULL && p != NULL) // ������ ��� ����, �� ��������� � �����
	{
		if(p->pr > temp->pr){
			p->next = temp;
			head = p;
			return;
		}
		while(true){
			if(temp->next==NULL || p->pr > temp->next->pr){
				p->next = temp->next;
				temp->next = p;
				return;
			}
			temp = temp->next;
		}
	}
	return;
}
/* �������� ����������� ������. */
void review(void)
{
	struct node *struc = head;
	if (head == NULL)
	{
		printf("������ ����\n");
	}
	while (struc)
	{
		printf("%s, %d ", struc->inf, struc->pr);
		struc = struc->next;
	}
	return;
}
struct node *find(char *name)
{
	struct node *struc = head;
	if (head == NULL)
	{
		printf("������ ����\n");
	}
	while (struc)
	{
		if (strcmp(name, struc->inf) == 0)
		{
			return struc;
		}
		struc = struc->next;
	}
	printf("������� �� ������\n");
	return NULL;
}
void del(char *name)
{
	struct node *struc = head; // ���������, ���������� �� ������ ���������� �� ������
	struct node *prev;// ��������� �� �������������� ���������� �������
	int flag = 0; // ��������� ���������� ���������� �������� � ������
	if (head == NULL) // ���� ������ ������ ����� NULL, �� ������ ����
	{
		printf("������ ����\n");
		return;
	}
	if (strcmp(name, struc->inf) == 0) // ���� ��������� ������� - ������
	{
		flag = 1;
		head = struc->next; // ������������� ������ �� ��������� �������
		free(struc); // ������� ������ �������
		struc = head; // ������������� ��������� ��� ����������� ������
	}
	else
	{
		prev = struc;
		struc = struc->next;
	}
	while (struc) // ������ �� ������ � ����� ���������� ��������
	{
		if (strcmp(name, struc->inf) == 0) // ���� �����, ��
		{
			flag = 1; // ���������� ���������
			if (struc->next) // ���� ��������� ������� �� ��������� � ������
			{
				prev->next = struc->next; // ������ ���������
				free(struc); // ������� �������
				struc = prev->next; // ������������� ��������� ��� �����������

			}
			else // ���� ��������� ������� ��������� � ������
			{
				prev->next = NULL; // �������� ��������� ���������������

				free(struc); // ������� �������
				return;

			}
		}
		else
		{
			prev = struc; // ������������� ��������� ��� ����������� ������
			struc = struc->next;
		}
	}
	if (flag == 0) // ���� ���� = 0, ������ ������ ������� ��
	{
		printf("������� �� ������\n");
		return;
	}
}
int main()
{
	setlocale(LC_ALL, "Rus");
	spstore();
	spstore();
	spstore();
	review();

	del("qwe");

	review();

	getchar();
	getchar();
	return 0;
}: \n ");
	scanf("%i", &(p->pr));
	p->next = NULL;
	return p;
}
void spstore(void)
{
	struct node *p = NULL, *temp = head;
	p = get_struct();
	if (head == NULL && p != NULL) // ���� ������ ���, �� ������������� ������
	{
		head = p;
	}
	else if (head != NULL && p != NULL) // ������ ��� ����, �� ��������� � �����
	{
		if(p->pr > temp->pr){
			p->next = temp;
			head = p;
			return;
		}
		while(true){
			if(temp->next==NULL || p->pr > temp->next->pr){
				p->next = temp->next;
				temp->next = p;
				return;
			}
			temp = temp->next;
		}
	}
	return;
}
/* �������� ����������� ������. */
void review(void)
{
	struct node *struc = head;
	if (head == NULL)
	{
		printf("������ ����\n");
	}
	while (struc)
	{
		printf("%s, %d ", struc->inf, struc->pr);
		struc = struc->next;
	}
	return;
}
struct node *find(char *name)
{
	struct node *struc = head;
	if (head == NULL)
	{
		printf("������ ����\n");
	}
	while (struc)
	{
		if (strcmp(name, struc->inf) == 0)
		{
			return struc;
		}
		struc = struc->next;
	}
	printf("������� �� ������\n");
	return NULL;
}
void del(char *name)
{
	struct node *struc = head; // ���������, ���������� �� ������ ���������� �� ������
	struct node *prev;// ��������� �� �������������� ���������� �������
	int flag = 0; // ��������� ���������� ���������� �������� � ������
	if (head == NULL) // ���� ������ ������ ����� NULL, �� ������ ����
	{
		printf("������ ����\n");
		return;
	}
	if (strcmp(name, struc->inf) == 0) // ���� ��������� ������� - ������
	{
		flag = 1;
		head = struc->next; // ������������� ������ �� ��������� �������
		free(struc); // ������� ������ �������
		struc = head; // ������������� ��������� ��� ����������� ������
	}
	else
	{
		prev = struc;
		struc = struc->next;
	}
	while (struc) // ������ �� ������ � ����� ���������� ��������
	{
		if (strcmp(name, struc->inf) == 0) // ���� �����, ��
		{
			flag = 1; // ���������� ���������
			if (struc->next) // ���� ��������� ������� �� ��������� � ������
			{
				prev->next = struc->next; // ������ ���������
				free(struc); // ������� �������
				struc = prev->next; // ������������� ��������� ��� �����������

			}
			else // ���� ��������� ������� ��������� � ������
			{
				prev->next = NULL; // �������� ��������� ���������������

				free(struc); // ������� �������
				return;

			}
		}
		else
		{
			prev = struc; // ������������� ��������� ��� ����������� ������
			struc = struc->next;
		}
	}
	if (flag == 0) // ���� ���� = 0, ������ ������ ������� ��
	{
		printf("������� �� ������\n");
		return;
	}
}
int main()
{
	setlocale(LC_ALL, "Rus");
	spstore();
	spstore();
	spstore();
	review();

	del("qwe");

	review();

	getchar();
	getchar();
	return 0;
}