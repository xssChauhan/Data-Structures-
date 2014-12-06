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

	while(p != NULL)
	{
		printf("%d \n", p->data);
		p = p->next;
	}
}

void InsertInLinkedList(  int data, int position){
	int k = 1;
	struct ListNode *p, *q, *newNode;
	newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
	if(!newNode)
	{
		printf("Memory Error");
		return;
	}
	if(head == NULL)
	{
		
		newNode->data = data;
		newNode->next = NULL;
		head = newNode;
		return;
		
	}
	newNode->data = data;
	p = head;
	
	//inserting at the beginning
	
	if(position == 1)
	{
		newNode->next  = p;
		head  = newNode;
	}
	else{
		//traverse the list until the position where we want to insert
		while((p != NULL) && (k<position))
		{
			
			k++;
			p = q;
			p = p->next;
		}
		q->next = newNode;
		newNode->next = p;
	}
}

void DeleteNodeFromLinkedList (int position){
	int k = 1;
	struct ListNode *p,*q;
	if( head == NULL )
	{
		printf("List Empty");
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
			printf("Position does not exist");
			
		}
		else{
			q->next = p->next;
			p->data = NULL;
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
		iterator->data = NULL;
		iterator->next = NULL;
		
	}	
	head = NULL;
}
int main()
{
	int data = 2;
	head = NULL;
	
	InsertInLinkedList( 5,1);
	DeleteLinkedList();
	printf("\n %d", ListLength());
	print();
	getch();
	return(0);
}
