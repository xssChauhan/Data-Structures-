#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10
typedef struct{
	int arr[MAX];
	int top;
}stack;

stack st = {{0}, -1};
void push(stack*, int);
int pop(stack*);
void show(stack*);

void push(stack *ptr, int d)
{
	if(ptr->top == MAX-1)
	{
		printf("The stack is full");
		return;
	}
	ptr->top++;
	ptr->arr[ptr->top] = d;
}

int pop(stack *ptr)
{
int d;
if(ptr->top == -1)
{
	printf("\n Stack is empty");
	return -1;
}
d = ptr->arr[ptr->top];
ptr->arr[ptr->top] == 0;
ptr->top--;
return d;	
}

void show(stack *ptr)
{
	int i=0;
	printf("\n The elements of the stack are:");
	for(i=0; i<=ptr->top;i++)
	{
		printf("\n %d",ptr->arr[i]);
		
	}
}

void main()
{
	int item,ch, del;
	do{
	
	printf("\n 1. Push");
	printf("\n 2. Pop");
	printf("\n 3. Display");
	printf("\n 4. Exit");
	scanf("%d", &ch);
	switch(ch)
	{
		case 1:
			printf("\n Enter the element to be inserted:");
			scanf("%d",&item);
			push(&st,item);
			break;
		case 2:
			del = pop(&st);
			printf("The item that has been deleted is %d", del);
			break;
		case 3:
			show(&st);
			break;
		case 4:
			printf("\n Good Bye");
			getch();
			exit(0);
			break;
		default:
			printf("wrong choice");
			break;
	}
	}while(ch>=1 && ch<=4);
	getch();	

}

