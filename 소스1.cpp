#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
#define _CRT_SECURE_NO_WARNINGS
//구조체 선언 정의
typedef struct stack {
	int arr[SIZE];
	int top;
}stack;
//스택 만들기 함수 선언
void createStack(stack* p);
//스택 만들기 함수 정의
void createStack(stack* p)
{
	p->top = -1;
}

//push 함수 선언
void push(stack* p, int element);
//push 함수 정의
void push(stack* p, int element)
{
	if (p->top == SIZE - 1)
	{
		printf("\n\n 스택이 꽉 찼습니다.");
		return;
	}
	p->arr[++(p->top)] = element;
}

//pop 함수 선언
int pop(stack* p);
//pop 함수 정의
int pop(stack* p)
{
	if (p->top == -1)
	{
		return -1;
	}
	return p->arr[(p->top)--];
}

//displayStack 함수 선언
void displayStack(stack* p);
//dispalyStack 함수 정의
void displayStack(stack* p)
{
	int i;
	printf("\n\n\t\tstack display(LIFO) : ");
	for (i = p->top; i >= 0; i--)
		printf("%d ", p->arr[i]);
	puts("");
}

//clearStack 함수 선언
void clearStack(stack* p);
//clearStack 함수 정의
void clearStack(stack* p)
{
	p->top = -1;
}


//메인 함수
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
			printf("\n push 하려는 데이터 입력 : ");
			scanf_s("%d", &value);
			push(&str, value);
			break;
		case 2:
			value =pop(&str);
			if (value == -1)
				printf("\n\n\t\t스택이 비었습니다.");
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


