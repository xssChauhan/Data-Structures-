#include<stdio.h>
#include<conio.h>

struct DLLNode{
	int data;
	struct DLL *next;
	struct DLL *prev;
}*head;

void insert(int data, int position)
{
	int k=1;
	struct DLLNode *temp, *newNode;
	newNode = (struct DLLNode *)malloc(sizeof(struct DLLNode));
	if(!newNode)
	{
		printf("Memory Error");
		return;
	}
	newNode->data = data;
	if(position == 1){
		newNode->next = head;
		newNode->prev = NULL;
		
		if(head)
		{
			head->prev = newNode;
			head = newNode;
			return;
		}
	}
	
	temp = head;
	while((k<position) && (temp->next != NULL))
	{
		temp = temp->next;
		k++;
	}
	if(k != position){
		printf("Desired Position does not exist");
		return;
	}
	newNode->next = temp->next;
	newNode->prev = temp;
	return;
	
}

int main()
{
	struct DLLNode *head;
	int a,i,p;
	head = NULL;
	while(1)
	{
		printf("Enter Your choice: \n 1. insert");
		scanf("%d" , &a);
		switch(a)
		{
			case 1:
			printf("Enter the number that you want to enter\n");
			scanf("%d \n", &i);
			printf("Enter the position at which you want to enter the number \n");
			scanf("%d", &p);
			insert(i,p);
			break;
			default:
			printf("Wrong choice \n");
			return 0;
			break;

		}
	}
	return 0;
}

