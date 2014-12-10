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
	while(1)
	{
		while(current!= NULL)
		{
			Push( current , stack );
			current = current->left;
		}
		if(isEmptyStack(stack))
			break;
		current = Pop(stack);
		printf("%d,\n", current->data);
		current = current->right;
	}
	return;
}

//traverse the Binary Tree Post Order
void PreOrderTraversal( struct Tree *p)
{
	struct Stack *stack = CreateStack();
	struct TreeNode *current = p->root;
	while(1)
	{
		while(current!=NULL)
		{
			printf("%d \n", current->data);
			Push(current, stack);
			current = current->left;
		}
		if(isEmptyStack(stack))
			break;
		current = Pop(stack);
		current = current->right;
	}
	return;
}

//traverse the Binary tree in PreOrder 
void PostOrderTraversal(struct Tree *p)
{
	struct Stack *stack = CreateStack();
	struct TreeNode *current = p->root;
	do
	{
		while(current != NULL)
		{
			if(current->right)
			{
				Push(current->right, stack);
			}
			Push(current, stack);
			current = current->left;
		}
		current= Pop(stack);
		if(current->right && stack->head->data == current->right)
		{
			Pop(stack);
			Push(current,stack);
			current = current->right;	
		}
		else
		{
			printf("%d \n", current->data);
			current = NULL;
		}
	}while(!isEmptyStack);
	return;
}


