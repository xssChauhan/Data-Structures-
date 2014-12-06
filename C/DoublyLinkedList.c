#include<stdio.h>
#include<conio.h>

struct DLLNode{
	int data;
	struct DLL *next;
	struct DLL *prev;
}*head;

void insert(int data, int position)
{
	printf("Entered Insert");
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

void DeleteNode(int position)
{
	struct DLLNode *temp, *temp2, *a;
	temp = head;
	int k = 1;

	if(head == NULL)
	{
		printf("List is empty");
		return;
	}
	if(position == 1)
	{
		head = head->next;
		head->prev =  NULL;
		temp->data = NULL;
		return;
	}
	while((k<position) && temp->next != NULL)
	{
		temp = temp->next;
		k++;	
	}
	if( k != position)
	{
		printf("Position does not exist");
		return;
	}
	temp2 = temp->prev;
	temp2->next = temp->next;
	temp->data = NULL;
	a = temp->next;
	if(temp->next)
	{
		a->prev = temp2;
	}
	temp->data = NULL;
	return;


}

int main()
{
	struct DLLNode *head;
	int a,i,p;
	head = NULL;
	while(1)
	{
		printf("Enter Your choice: \n 1. insert \n 2. Delete Node \n");
		scanf("%d" , &a);
		switch(a)
		{
			case 1:
			printf("Enter the number and the position that you want to enter a\n");
			scanf("%d %d \n", &i, &p);
			
			insert(i,p);
			break;
			case 2:
			printf("Enter the position from which you want to delete the node \n");
			scanf("%d", &p);
			DeleteNode(p);
			default:
			printf("Wrong choice \n");
			return 0;
			break;

		}
	}
	return 0;
}

