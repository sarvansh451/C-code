#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>

struct node {
    struct node *left;
    int data;
    struct node* right;
};
struct node* create(struct node* root, int n)
{
    struct node* newnode = (struct node* )malloc(sizeof(newnode));;
    newnode -> data= n;
    newnode -> left =0;
    newnode -> right =0;

    if( root == NULL)
    {
        return newnode;
    }
    else
    {
        struct node* ptr= root;
        struct node* parent;
        while(ptr != NULL)
        {
            parent = ptr;
            if(n<ptr->data)
            {
                ptr=ptr->left;
            }
            else
            {
                ptr=ptr->right;
            }
        }
        if(n<parent->data)
        {
            parent->left = newnode;
        }
        else
        {
            parent->right = newnode;
        }
        return root;
    }
}
int smallest(struct node* root)
{
    if(root == NULL)
    {
        return INT_MIN;
    }
    else
    {
        while(root->left != NULL)
        {
            root = root ->left;
        }
        return root->data;
    }
}
int largest(struct node* root)
{
    if(root == NULL)
    {
        return INT_MIN;
    }
    else
    {
        while(root->right != NULL)
        {
            root = root -> right;
        }
        return root->data;
    }
}
int height(struct node* root)
{
    if(root==0)
    {
        return 0;
    }
    else
    {
        return fmax(height(root->left)+1,height(root->right)+1);
    }
}
int main()
{
    struct node* root = 0;
    int ch;
    printf("The size of the node is %ld \n",sizeof(struct node));
    do
    {
        printf("MAIN MENU\n");
        printf("0. To exit the program\n");
        printf("1. To insert an element in the Binary search tree\n");
        printf("2. To find the smallest element in the Binary Search Tree\n");
        printf("3. To find the largest element in the Binary Search Tree\n");
        printf("4. To find the hegit of the Binary Search tree\n");
        printf("Enter choice : \t");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter an element to insert in the BST\n");
                int num;
                scanf("%d",&num);
                root=create(root,num);
                break;
            case 2:
                printf("The smallest element in the BST is %d \n",smallest(root));
                break;
            case 3:
                printf("The largest element in the BST is %d \n",largest(root));
                break;
            case 4:
                printf("The height of the tree is %d \n",height(root));
                break;
        }

    } while (ch!=0);
    
}

