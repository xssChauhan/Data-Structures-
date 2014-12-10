#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//Node of the Tree
struct TreeNode{
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
};

//Node of the stack
struct StackNode{
	struct TreeNode *data;
	struct StackNode *next;
};

//Stack. Information contained is the root node of the stack
struct Stack{
	struct StackNode *head;
};

//Tree. Information contained is the root of the Tree
struct Tree{
	struct TreeNode *root;
};

//Create a node of the Tree
struct TreeNode *CreateTreeNode()
{
	 struct TreeNode *p = malloc(sizeof(struct TreeNode));
	 if(!p)
	 {
	 	printf("Memory Error \n");
	 	return NULL;
	 }
	 return p;
	 
}

//Create the Stack
struct Stack *CreateStack()
{
	struct Stack *p = malloc(sizeof(struct Stack));
	if(!p)
	 {
	 	printf("Memory Error \n");
	 	return NULL;
	 }
	 return p;
	
}

//Create the stack node
struct StackNode *CreateStackNode()
{
	struct StackNode *p = malloc(sizeof(struct StackNode));
	if(!p)
	 {
	 	printf("Memory Error \n");
	 	return NULL;
	 }
	 return p;
}


//Create the Tree
struct Tree *CreateTree()
{
	struct Tree *p = malloc(sizeof(struct Tree));
	if(!p)
	 {
	 	printf("Memory Error \n");
	 	return NULL;
	 }
	 return p;
	 
	 //Write Code to enter data into tree
	
}
int isEmptyStack(struct Stack *p)
{
	return (p == NULL);
}

void Push(struct TreeNode *q, struct Stack *p)
{
	struct StackNode *newNode =  CreateStackNode();
	newNode->data = q;
	if(p == NULL)
	{
		newNode->next = NULL;
		p->head = newNode;
		return;
	}
	newNode->next = p->head;
	p->head = newNode;
	return;
}

struct TreeNode *Pop( struct Stack *p)
{
	struct TreeNode *q;
	struct StackNode *s;
	if(isEmptyStack(p))
	{
		printf("Stack is empty \n");
		return;
	}
	q = p->head->data;
	s = p->head;
	p->head = p->head->next;
	free(p);
	return q;
	
}
//traverse the Binary In Order
void InOrderTraversal(struct Tree *p)
{
	struct Stack *stack =  CreateStack();
	struct TreeNode *current = p->root;
	int done = 0;
	while(!done)
	{
		while(current!= NULL)
		{
			Push( current , stack );
			current = current->left;
		}
		while( !isEmptyStack(stack) )
		{
			current = Pop(stack);
			printf("%d\n", current->data);
			current = current->right;
		}
		if(isEmptyStack(stack))
		{
			done = 1;
		}
	}
	return;

	
}

//traverse the Binary Tree Post Order
void PostOrderTraversal( struct Tree *p)
{
	struct Stack *stack = CreateStack();
}

//traverse the Binary tree in PreOrder 
void PreOrderTraversal(struct Tree *p)
{
	struct Stack *stack = CreateStack();
}


