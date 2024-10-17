#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node*left;
	struct node*right;
	}BST;
	
BST* tree=NULL;
BST* insert(int val);
BST* largest(BST* tree)
{
	if(tree==NULL||tree->right==NULL)
	{
		return tree;
	}
	else
	{
		return (largest(tree->right));
	}
}
	
BST* smallest(BST *tree)
{
	if(tree==NULL||tree->left==NULL)
	{
		return tree;
	}
	else
	{
		return(smallest(tree->left));
	}
}		
		
int height(BST* tree)
{
	int leftheight;
	int rightheight;
	if(tree==NULL)
	{
		return 0;
	}
	leftheight=height(tree->left);
	rightheight=height(tree->right);
	if(leftheight>rightheight)
	{
		return (leftheight+1);
	}
	else{
		return(rightheight+1);
	}
}
 BST* insert(int val)
 {
 	BST* ptr=(BST*)malloc(sizeof(BST));
 	BST* parentptr;
 	BST* nodeptr;
 	ptr->data=val;
 	ptr->left=NULL;
 	ptr->right=NULL;
 	if(tree==NULL)
 	{
 		tree=ptr;
 		ptr->left=NULL;
 		ptr->right=NULL;
	 }
	 else
	 {
	 	parentptr=NULL;
	 	nodeptr=tree;
	 	while(nodeptr!=NULL)
	 	{
	 		parentptr=nodeptr;
	 		if(nodeptr->data>val)
	 		{
	 			nodeptr=nodeptr->right;
			 }
			 else
			 {
			 	nodeptr=nodeptr->left;
			 }
		 }
		 if(parentptr->data>val)
		 {
		 	parentptr->right=ptr;
		 }
		 else
		 {
		 	parentptr->left=ptr;
		 }
		 
	 }
	 return tree;
 }
 int height()
 {
 	int leftheight;
 	int rightheight;
 	if(tree==NULL)
 	{
 		return 0;
	 }
	 leftheight=height(tree->left);
	 rightheight=height(tree->right);
 	if(leftheight>rightheight)
 	{
 		return leftheight+1;
	 }
	 else
	 {
	 	return rightheight+1;
	 }
 }
	//8 3 10 1 6 14 4 7 12//
int main()
{

	insert(8);
	insert(3);
	insert(10);
	insert(1);
	insert(6);
	insert(14);
	insert(14);
	insert(7);
	insert(12);

       tree=largest(tree);
       printf("largest element=%d\n",tree->data);
       tree=smallest(tree);
       printf("smallest element=%d\n",tree->data);
       int H=height(tree);
       printf("height of the tree=%d\n",H);
       return 0;
	
	}	
	//code cannot run for thiscomplier//
	// sad lol//
