#include<stdio.h>
#include<conio.h>

int tree[100], t;

void insert(int );
int search(int );
void del( int );
void display();
//insert data into the tree
void insert(int data)
{
	if(t==1)
	{	
		int x;
		tree[t++] = data;
		return;
	}	
	x = search(1,data);
	if(tree[x] > data)
	{
		tree[2*x] = data;
	}
	else if(tree[x] < data )
	{
		tree[2*x + 1] = data;
	}
	t++;
	
}
//returns the parent of the element
int search1(int s,int data)
{
	if(t==1)
	{
		printf("The element does not exits \n");
		return;
	}
	else if( tree[s] == -1)
	{
		return s/2;
	}
	else if( tree[s] > data)
	{
		search(2*s,ch);
	}
	else if(tree[s] < )
	{
		search(2*s + 1,data);
	}
}

int search(int s,int data)
{
	if(t==1)
	{
		printf("The element does not exits \n");
		return;
	}
	else if( tree[s] == -1)
	{
		return s/2;
	}
	else if( tree[s] > data)
	{
		search(2*s,data);
	}
	else if(tree[s] < data)
	{
		search(2*s + 1,data);
	}
	else
	{
		return s;
	}
}

void delete(int data)
{
	if(tree[2*x] == -1 && tree[2*x + 1] == -1)
	{
		tree[x] = -1;
	}	
	else if(tree[2*x] == -1)
	{
		tree[x] == tree[2*x + 1];
		tree[2*x + 1] = -1;
	}
	else if(tree[2*x +1 ] == -1)
	{
		tree[x] == tree[2*x];
		tree[2*x] == -1;
	}
	else
	{
		tree[x] = tree[2*x];
	}
	t--;
}



