#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Stack{
	int data;
	struct Stack *next;
}*head;

struct Stack *Create()
{
	struct Stack *S;
	S = (struct Stack *)malloc(sizeof(struct Stack));
	if(!S)
	{
		printf("Memory not available \n");
		return NULL; 
	}
	return S;
}

void Push(int data)
{
	struct Stack *newNode;
	newNode = Create();
	newNode->data = data;
	newNode->next = head;
	head = newNode;
	
}

int Pop()
{
	int data;
	struct Stack *p;
	if(head == NULL)
	{
		printf("The stack is empty");
		return 0;
	}
	p = head;
	head = head->next;
	data = p->data;
	free(p);
	return data;
}

int StackLength()
{
	struct Stack *p;
	p = head;
	int count = 0;
	while( p!= NULL )
	{
		count++;
		p = p->next;
	}
	return count;
}

void Print()
{
	struct Stack *p;
	p = head;
	printf("The Stack is :\n");
	if( head ==  NULL)
	{
		printf("Stack is empty");
		return;
	}
	while(p!=NULL)
	{
		printf("%d \n", p->data);
		p = p->next;
	}
	return;
}

void DeleteStack()
{
	struct Stack *p,*q;
	p = head;
	while(p != NULL )
	{
		q = p->next;
		free(p);
		p=q;
	}
	return;
}

int main(){
	int a, i;
	
	while(1)
	{
		printf("Enter your choice \n 1. Push \n 2. Pop \n 3.Print \n 4. Stack Length \n 5. Delete Stack \n 6. Exit \n");
		scanf("%d", &a);	
		switch(a)
		{
			case 1:
				printf("Enter the data you want to enter \n");
				scanf("%d", &i);
				Push(i);
				break;
			case 2:
				printf("The popped element is %d \n" , Pop());
				break;
			case 3:
				Print();
				break;
			case 4:
				printf("The length of the stack is %d", StackLength());
				break;
			case 5:
				DeleteStack();
				break;
			case 6:
				return 0;
				break;
			default:
				printf("Wrong choice");
				break;
			
		}
	}
	return 0;
}
