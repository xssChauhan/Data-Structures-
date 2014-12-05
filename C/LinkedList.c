#include<conio.h>
#include<stdio.h>
struct ListNode{
	int data;
	struct ListNode *next;
}*head;

int ListLength( struct ListNode* head){
	struct ListNode *current  = head;
	int count = 0;
	
	while( current != NULL){
		count++;
		current = current->next;
	}
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
		printf("head  null");
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
			printf("go");
			k++;
			p = q;
			p = p->next;
		}
		q->next = newNode;
		newNode->next = p;
	}
}

int main()
{
	int data = 2;
	head = NULL;
	printf("hello");
	InsertInLinkedList( 5,1);
	print();
	getch();
	return(0);
}
