#include<stdio.h>
#include<conio.h>

struct QueueArray{
	int front, rear;
	int *array;
	int capacity;
};

struct QueueArray *Create()
{
	struct QueueArray *p;
	p = (struct QueueArray *)malloc(sizeof(struct QueueArray));
	if(!p)
	{
		printf("Memory error\n");
		return;
	}
	p->capacity = 1;
	p->front = -1;
	p->rear = -1;
	p->array = malloc(sizeof(p->capacity * (sizeof(int))));
	return p;
}

int isFullQueue( struct QueueArray *p)
{
	return ( (p->rear+1)%(p->capacity) == p->front);
}

int isEmptyQueue( struct QueueArray *p)
{
	return( p->front == -1);
}

void EnQueue( int data, struct QueueArray *p )
{
	if( isFullQueue(p) )
	{
		ResizeQueue(p);
	}
	p->rear = (p->rear+1)%p->capacity;
	p->array[p->rear] = data;
	if(p->front == -1)
	{
		p->front = p->rear;
	}
}

int DeQueue( struct QueueArray *p)
{
	int data = 0;
	if(isEmptyQueue(p))
	{
		printf("The Queue is empty \n");
		return 0;
	}
	data = p->array[p->front];
	if(p->front == p->rear)
	{
		p->front = p->rear = -1;
		return data;
	}
	p->front = (p->front+1)%p->capacity;
	return data;
	
}

void ResizeQueue( struct QueueArray *p)
{
	int size = p->capacity;
	int i = 0;
	p->capacity = p->capacity*2;
	p->array = realloc(p->array, p->capacity);
	if(!p->array)
	{
		printf("Memory error \n");
		return;
	}
	if( p->front > p->rear)
	{
		for ( i =0; i<p->front;p++)
		{
			p->array[i+size] = p->array[i];
			
		}	
		p->rear = p->rear+ size;
	}
	return;
}

int QueueSize( struct QueueArray *p)
{
	if(isFullQueue(p))
	{
		return p->capacity;
	}
	return (p->capacity + p->rear - p->front + 1)%p->capacity;
}
void DeleteQueue( struct QueueArray *p)
{
	if(p)
	{
		free(p->array);
	}
	free(p);
	return;
}



int main()
{
	struct QueueArray *s;
	s = Create();
	EnQueue(5,s);
	printf("%d", s->array[0]);
return 0;	
}
