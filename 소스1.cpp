#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
#define _CRT_SECURE_NO_WARNINGS
//����ü ���� ����
typedef struct stack {
	int arr[SIZE];
	int top;
}stack;
//���� ����� �Լ� ����
void createStack(stack* p);
//���� ����� �Լ� ����
void createStack(stack* p)
{
	p->top = -1;
}

//push �Լ� ����
void push(stack* p, int element);
//push �Լ� ����
void push(stack* p, int element)
{
	if (p->top == SIZE - 1)
	{
		printf("\n\n ������ �� á���ϴ�.");
		return;
	}
	p->arr[++(p->top)] = element;
}

//pop �Լ� ����
int pop(stack* p);
//pop �Լ� ����
int pop(stack* p)
{
	if (p->top == -1)
	{
		return -1;
	}
	return p->arr[(p->top)--];
}

//displayStack �Լ� ����
void displayStack(stack* p);
//dispalyStack �Լ� ����
void displayStack(stack* p)
{
	int i;
	printf("\n\n\t\tstack display(LIFO) : ");
	for (i = p->top; i >= 0; i--)
		printf("%d ", p->arr[i]);
	puts("");
}

//clearStack �Լ� ����
void clearStack(stack* p);
//clearStack �Լ� ����
void clearStack(stack* p)
{
	p->top = -1;
}


//���� �Լ�
void main()
{
	int choice = 0 , value = 0;
	stack str;
	createStack(&str);
	while(1)
	{
		printf("\n\n\t\t Stack \n\n");
		printf("\t\t 1.	push		2.pop		3. print		4. clear		0. exit\n");
		printf("\t\tchoice : [ ]\b\b");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("\n push �Ϸ��� ������ �Է� : ");
			scanf_s("%d", &value);
			push(&str, value);
			break;
		case 2:
			value =pop(&str);
			if (value == -1)
				printf("\n\n\t\t������ ������ϴ�.");
			else 
				printf("\n\n\t\t%d pop \n", value);
			break;
		case 3:
			displayStack(&str);
			break;
		case 4:
			clearStack(&str);
			break;
		case 0:
			exit(0);
		}
	}
}


