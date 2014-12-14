#include<stdio.h>
#include<conio.h>

struct Heap{
	int *array;
	int count;
	int capacity;
	int heap_type;
};

struct Heap *CreateHeap(int capacity, int heap_type)
{
	struct Heap *h = malloc(sizeof(struct Heap));
	if(!h)
	{
		printf("Memory Error");
		return;
	}
	h->heap_type = heap_type;
	h->count == 0;
	h->capacity = capacity;
	h->array = (int *)malloc(sizeof((int)*h->capacity));

	if(!h->array)
	{
		printf("Memory Error");
		return;
	}
	return h;

}

//finding the parent element of the given element

int Parent(struct Heap *h, int i)
{
	if( i<=0 && i > h->count )
	{
		return -1;
	}
	return(i-1)/2;
}

//finding the left child

int LeftChild(struct Heap *h, int i)
{
	int left;
	left = 2*i + 1;
	if( left > h->count)
	{
		return -1;
	}
	return left;
}
 //finding the right child
int RightChild( struct Heap *h, int i)
{
	int right = 2*1 + 2;
	if( right >= h->count)
	{
		return -1;
	}
	return right;
}

//Get the maximum element of the Heap
int GetMaximum (struct Heap *h)
{
	if(h->count == 0)
	{
		return -1;
	}
	return h->array[0];
}

//Percolate Down. Used to Heapify the element that is out of place

void PercolateDown( struct Heap *h, int i)
{
	int l, r, max, temp;
	l = LeftChild(h, i);
	r = RightChild(h, i);

	if(l != -1 && h->array[l] > h->array[i])
	{
		max = l;
	}
	else
	{
		max = i;
	}
	if( r != -1 && h->array[r] >= h->array[max])
	{
		max = r;
	}
	if( max != i )
	{
		//Swap the elements
		temp  = array[i];
		array[i] = array[max];
		array[max] = temp;
	}
	PercolateDown(h, max);
}

//Deleting Maximum element

int DeleteMax( struct Heap *h)
{
	
}