#include<stdio.h>
#include<stdlib.h>

struct Heap{
	int *array;
	int count;
	int capacity;
};

struct Heap *CreateHeap(int capacity)
{
	struct Heap *h = malloc(sizeof(struct Heap));
	if(!h)
	{
		printf("Memory Error");
		return;
	}
	h->count == 0;
	h->capacity = capacity;
	h->array = (int *)malloc(sizeof(int)*h->capacity);

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
		temp  = h->array[i];
		h->array[i] = h->array[max];
		h->array[max] = temp;
	}
	PercolateDown(h, max);
}

/*Deleting Maximum element
1. Make the last element of the heap the first element
2. Decrease the count of the heap by one
3. Percolate down the new root element to the correct place
4. return data
*/

int DeleteMax( struct Heap *h)
{
	int data;
	data = h->array[0];
	h->array[0] = h->array[h->count];
	h->count--;
	PercolateDown(h,0);
	return data;
}

/*
Resizing The Heap using repeated doubling
1. Double The capacity of the heap
2. Reallocate the memory to the heap array
3. return heap
*/
struct Heap *ResizeHeap( struct Heap *h)
{
	h->capacity = h->capacity*2;
	h->array = realloc(h->array, h->capacity);
	if(!h->array)
	{
		printf("Cannot extend array size\n");
	}
	return h;
}

/*
inserting an element into the heap
1. Check if the heap is out of memory. If so, Resize the array.
2. Inserting the element the element at the end of the list
3. Iterate with the condition that element is being added at a position that is greater than zero and the data is greater than is parent element
*/

void Insert(struct Heap *h, int data)
{
	int i, temp;
	if(h->count == h->capacity || h->count >= h->capacity)
	{
		h = ResizeHeap(h);
	}
	h->array[++h->count] = data;
	i = h->count;
	while( i >= 0 && h->array[i] > h->array[(i-1)/2])
	{
		temp = h->array[i];
		h->array[(i-1)/2] = h->array[i];
		h->array[i] = temp;
		i = (i-1)/2;
	}
	
	return;
}

/*
Deleting Array
1. Free the array
2. Free the heap
*/
void DeleteHeap(struct Heap *h)
{
	free(h->array);
	free(h);
	h = NULL;
	return;
}

/*
Building a Heap from an array or Heapifying the Array
1. Resize the heap array if size exceeds
2. Copy the array into the heap
3. Percolate Down from the Parent of the last element, or the leaf
*/
void BuildHeap( struct Heap *h, int A[], int n)
{
	int i;
	if(n>h->capacity)
	{
		h = ResizeHeap(h);
	}	
	for(i = 0; i< n; i++)
	{
		h->array[i] = A[i];
	}
	for(i= (n-1)/2; i>=0; i--)
	{
		PercolateDown(h, i);
	}
	return;
}

/*
Heapsort: Input the built array
2. Delete the top element
3. Run until the array is empty
*/
void *HeapSort( struct Heap *h)
{	
	int i;
	i = h->count;
	while(i>=0)
	{
		printf("%d \n", DeleteMax(h));
		i = h->count;
	}
}



int main()
{
	printf("Hello World");
	return 0;
}