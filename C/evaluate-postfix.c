#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

struct StackNode{
	int data;
	struct StackNode *next;
};

struct Stack{
	struct StackNode *head;
};

struct Stack *CreateStack()
{
	struct Stack *p = malloc(sizeof(struct Stack));
	if(!p)
	{
		printf("Memory Error");
		return;
	}
	return p;
}

struct StackNode *CreateNode()
{
	struct StackNode *p = malloc(sizeof(struct StackNode));
	if(!p)
	{
		printf("Memory Error");
		return;
	}
	return p;
	
}

void Push(struct Stack *stack, int data)
{
	struct StackNode *newNode = CreateNode();
	newNode->data = data;
	if(stack == NULL)
	{
		newNode->next = NULL;
		stack->head = newNode;
		return;	
	}
	newNode->next = stack->head;
	stack->head = newNode;
	return;
}

int Pop(struct Stack *stack)
{
	int data;
	if(stack->head == NULL)
	{
		printf("Stack Empty \n");
		return;
	}
	data = stack->head->data;
	stack->head = stack->head->next;
}
int calculate(int p, int q, char *x)
{
	switch(*x)
	{
		case '+':
		return p+q;
		break;
		case '-':
		return q-p;
		break;
		case '/':
		return q/p;
		break;
		case '*':
		return q*p;
		break;
		case '%':
		return q%p;
		break;
		case '^':
		return pow(q,p);
		break;
		default:
		printf("Wrong operator \n");
		return;
		break;
	}
}
int evaluate( char *exp)
{
	struct Stack *stack = CreateStack();
	int p,q;
	while(*exp)
	{
		if(*exp == '' || *exp == '\t')
		{
			exp++;
			continue;
		}
		else if( isdigit(*exp))
		{
			Push(stack, (*exp)-48);
		}
		else
		{
			p = Pop(stack);
			q = Pop(stack);
			Push(stack,calculate(p,q,exp));

		}
		exp++;
		
	}
}
