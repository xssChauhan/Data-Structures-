#include<conio.h>
#include<stdio.h>
struct ListNode{
	int data;
	struct ListNode *next;
}*head;

int ListLength( ){
	struct ListNode *current  = head;
	int count = 0;
	
	while( current != NULL){
		count++;
		current = current->next;
	}
	return count;
}
void print()
{
	struct ListNode *p;
	p = head;
	printf("The list: \n");

	while(p != NULL)
	{
		printf("%d \n", p->data);
		p = p->next;
	}
	return;
}

void InsertInLinkedList(  int data, int position ){
	
	int k =1;
	struct ListNode *newNode, *p, *q;
	newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
	if(!newNode)
	{
		printf("Memory Error \n");
	}
	p = head;
	newNode->data = data;
	//insertion in case of empty list
	if(head == NULL)
	{
		head = newNode;
		newNode->next = NULL;
		return;
	}
	//insertion at the head
	if(position == 1)
	{
		newNode->next = head;
		head = newNode;
		return;
	}
	//insertion at intermediate positions and the end
	while( (k<position) && (p->next != NULL))
	{
		k++;
		q = p;
		p = p->next;
	}
	
	if(p->next){
	
		q->next = newNode;
		newNode->next = p;
		return;
	}
	//insertion at the end of the list
	p->next = newNode;
	newNode->next = NULL;
	return;
}

void DeleteNodeFromLinkedList (int position){
	int k = 1;
	struct ListNode *p,*q;
	if( head == NULL )
	{
		printf("List Empty\n");
		return;
	}
	p = head;
	//from the beginning 
	if(position == 1)
	{
		head = head->next;
		p->data = NULL;
		return;
	}
	else{
		//traverse the list until the position from which we want tos delete 
		while( (p!= NULL) && (k<position))
		{
			k++;
			q = p;
			p =p->next;
		}
		if( p == NULL )
		{
			printf("Position does not exist\n");
			
		}
		else{
			q->next = p->next;
			free(p);
		}
	}
}

void DeleteLinkedList()
{
	struct ListNode *auxiliaryNode, *iterator;
	iterator = head;
	while(iterator)
	{
		auxiliaryNode = iterator->next;
		free(iterator);
		iterator = auxiliaryNode;
		
	}	
	head = NULL;
}
int main()
{
	int a,i,p;
	head =  NULL;
	while(1)
	{
		printf("Enter a choice \n 1. Insert \n 2. Delete Node \n 3. Print List \n 4. Print List Length \n 5. Delete List \n 6. Exit\n");
		scanf("%d", &a);
	
			switch(a)
			{
				case 1:
				printf("Enter the number you want to enter\n");
				scanf("%d", &i);
				printf("Enter the position at which you want to enter the data\n");
				scanf("%d", &p);
				InsertInLinkedList(i,p);
				break;
				case 2:
				printf("Enter the position from which you want to delete \n");
				scanf("%d", &p);
				DeleteNodeFromLinkedList(p);
				break;
				case 3:
				print();
				break;
				case 4:
				printf("%d",ListLength());
				break;
				case 5:
				DeleteLinkedList();
				break;
				case 6:
				return 0;
				break;
				default:
				return 0;
				break;
			}
		}
		
	return 0;
}
