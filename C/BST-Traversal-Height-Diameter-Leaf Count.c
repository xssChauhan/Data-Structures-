#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
	int data;
	struct TreeNode *right;
	struct TreeNode *left;
};

struct Queue{
	int arr[100];
	int head;
	int tail;
};

struct TreeNode *newTreeNode(){
	struct TreeNode *node = malloc(sizeof(struct TreeNode));
	if(node){
		node->data;
		node->left = NULL;
		node->right = NULL;
		return node;
	}
	else{
		printf("Memory Error");
	}
}




struct Queue *createQueue(){
	struct Queue *q = malloc(sizeof( struct Queue));
	if( !q ){
		printf("Memory Error, the queue could not be creater");
		return;
	}
	else
		return q;
}

void EnQueue(struct Queue *q, int data){
	int tail = q->tail;
	if(tail < 0 || tail > 99){
		printf("Data overflow");
		return;
	}
	else{
		q->arr[tail] = data;
		q->tail += 1;
		if( q->tail > 99){
			q->tail = q->tail%99;
		}
	}
}

int DeQueue( struct Queue *q){
	if(q->head < 0 || q->head > 99){
		printf("Data Overflow");
		return;
	}
	else{
	  int data = q->arr[q->head++];
	  if( q->head > 99){
	  	q->head = q->head%99;
	  }
	  return data;
	}
}

void InorderTraversalRecursive(struct TreeNode *node){
	if(!node){
		return;
	}
	InorderTraversalRecursive(node->left);
	printf("%d \n",node->data);
	InorderTraversalRecursive(node->right);
}

void PreOrderTraversalRecursive(struct TreeNode *node){
	if(!node){
		return;
	}
	printf("%d \n",node->data);
	PreOrderTraversalRecursive(node->left);
	PreOrderTraversalRecursive(node->right);
}

void PostOrderTraversal(struct TreeNode *node){
	if(!node){
		return;
	}
	PostOrderTraversal(node->left);
	PostOrderTraversal(node->right);
	printf("%d \n",node->data);
}
struct TreeNode *InsertIntoTree(struct TreeNode *node, int data){

	if(node == NULL){

		node = newTreeNode();
		node->data = data;

		node->left = node->right = NULL;
	}
	else{
		if(data >= node->data){

			node->right = InsertIntoTree(node->right, data);
		}
		else if(data <= node->data)
			node->left = InsertIntoTree(node->left, data);
	}
	return node;

}

struct TreeNode *MakeTreeFromData(int *arr){
	struct TreeNode *root,*node;
	root = newTreeNode();
	node = root;
	root->data = arr[0];

	int i;
	for(i=1;i<8;i++){
		InsertIntoTree(node,arr[i]);

	}
	return root;
}

int HeightOfBinaryTree(struct TreeNode *root){
	int leftheight, rightheight;
	if( root == NULL){
		return 0;
	}
	else{
		leftheight = HeightOfBinaryTree(root->left);
		rightheight = HeightOfBinaryTree(root->right);

		if(leftheight > rightheight)
			return leftheight + 1;
		else
			return rightheight + 1;
	}
}

int max( int a , int b){
	return (a > b)?a:b;
}

int DiameterBinaryTree( struct TreeNode *root, int *ptr){
	int left, right;
	if(!root)
		return 0;
	left = DiameterBinaryTree(root->left, ptr);
	right = DiameterBinaryTree(root->right, ptr);

	if( left + right > *ptr)
		*ptr = left + right;
	return max(left, right) + 1;
}

void CountLeaves(struct TreeNode *root, int *count){
	if(!root)
		return;
	if(!root->left && !root->right){
		*count = *count + 1;
		return;
	}
	else{
		CountLeaves(root->left,count);
		CountLeaves(root->right,count);
	}
}

int CountLevelsTree(struct TreeNode *root){
	int temp levels = 0;
	struct Queue *q = createQueue();
	EnQueue(q, root->data);
	EnQueue(q, NULL);
	while(!IsEmptyQueue){
		temp = DeQueue(q);
		if(temp == NULL){
			levels++;
			if(!IsEmptyQueue)
				EnQueue(q, NULL);
		}
		else{
			if(temp->right)
				EnQueue(q,temp->right);
			if(temp->left)
				EnQueue(q, temp->left);
		}
		

			
	}
}

void main(){
	int data[] = {4,2,6,1,7,3,5,8};
	int i;
	struct TreeNode *root;
	root = MakeTreeFromData(data);
	printf("Inorder Traversal\n");
	InorderTraversalRecursive(root);
	printf("Preorder Traversal \n");
	PreOrderTraversalRecursive(root);
	printf("PostOrderTraversal \n");
	PostOrderTraversal(root);
	int h = HeightOfBinaryTree(root);
	printf("The height of Binary Tree is %d \n", h);
	int *dia = malloc(sizeof(int));
	DiameterBinaryTree(root, dia);
	printf("The diameter of the binary tree is %d \n", *dia);
	int *count = malloc(sizeof(int));
	*count = 0;
	CountLeaves(root, count);
	printf("The number of nodes in the tree are %d \n" , *count);

}

