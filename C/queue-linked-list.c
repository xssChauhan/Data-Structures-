#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};

struct Queue{
	struct Node *rear;
	struct Node *front;
};

struct Queue *CreateQueue()
{
	struct Queue *Q = malloc(sizeof(struct Queue));
	if(!Q)
	{
		printf("Memory error \n");
	}
	Q->front = Q->rear = NULL;
	return Q;
}

struct Node *CreateNode()
{
 struct Node *p = malloc(sizeof(struct Node));
 if(!p)
 {
 	printf("Memory Error");
 	return;	
 }
 return p;
 }
 
 int isEmptyQueue(struct Queue *p)
 {
	return (p->front ==  NULL);
 }
 
 void EnQueue( struct Queue *p, int data)
 {
 	struct Node *newNode = CreateNode();
 	newNode->data = data;
 	if( p->front == NULL)
 	{
 		p->front = p->rear = newNode;
 		return;
 	}
 	p->rear = p->rear->next;
 	p->rear = newNode;
 	return;
 }
 
 int DeQueue( struct Queue *p)
 {
 	int data;
 	struct Node *temp = CreateNode();
 	if( isEmptyQueue(p))
 	{
 		printf("The Queue is empty \n");
 		return 0;
 	}
 	temp = p->front;
 	data = temp->data;
 	p->front = p->front->next;
 	free(temp);
 	return data;
 }
 
 int QueueLength( struct Queue *p)
 {
 	int count = 0;
 	struct Node *q;
 	q = p->front;
 	while(q->next != NULL)
 	{
 		count++;
		 q = q->next;	
 	}
 	return count;
 }
 
 int main()
 {
 	int a;
 	struct Queue *p = CreateQueue();
 	while(1)
 	{
 		printf("Enter a choice \n 1. Insert \n 2. Delete Node \n 3. Queue Length \n 4. Exit \n");
 		scanf("%d", &a);
 		switch(a)
 		{
 			case 1:
 				printf("Enter a number to enter \n");
 				scanf("%d", &a);
 				EnQueue(p,a);
 				break;
 			case 2:
 				printf("The deleted element is %d \n", DeQueue(p));
 				break;
 			case 3:
 				printf("The length of the queue is %d \n", QueueLength(p));
 				break;
 			case 4:
 				return 0;
 				break;
 			default:
 				printf("Wrong Choice\n");
 				break;
 				
 		}
 	}
 	return 0;
 }
