//operations in a circular singly linked list//
#include<stdio.h>
#include<stdlib.h>
 typedef struct node 
 {
    int data;
    struct  node *next;
}node;

node *start=NULL;
   node *create(node *);
   node * display(node *);
   node * delete_after(node *);
   node * delete_end(node *);
   node * delete_begin(node *);
   node *insertafter(node *);
   node *insertend(node *);
   node *insertbegin(node *);
    node *sort(node *);
int main()
{
	int choice;
	do{
	  printf("\n****MAIN MENU****\n");
        printf("\nChoose the operations to be performed from given option: ");
        printf("\n1. Create a circular Linked List");
        printf("\n2. Traverse a linked list");
        printf("\n3. delete after a node");
        printf("\n4. Delete the beg element");
        printf("\n5. Delete the end element");
        printf("\n6. insert after an element");
        printf("\n7. Insert at beg ");
        printf("\n8. Insert at the end");
        printf("\n9.sort circular linked list");;
        printf("\n10. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
                start=create(start);
                printf("\nThe Circular Linked list created\n");
                break;
            case 2:
                start= display(start);
                break;
            case 3:
                start= delete_after(start);
                break;
            case 4:
                start= delete_begin(start);
                break;
            case 5:
                start= delete_end(start);
                break;
            case 6:
                start=insertafter(start);
                break;
            case 7:
                start=insertbegin(start);
                break;
            case 8:
                start=insertend(start);
                break;
             case 9:
                start=sort(start);
                break;
            case 10:
                printf("Exiting the program");
                break;
        }
    }
    while(choice!=10);
    return 2;
        
}
node* create(node* start)
   {
       node* new_node, *ptr;
    int num;
    printf("\nEnter -1 to end\n");
    printf("\nEnter the data:");
    scanf("%d",&num);
    while(num!=-1)
    {
        new_node=(node*)malloc(sizeof(node));
        new_node->data=num;
        if (start==NULL)
        {
            start=new_node;
            new_node->next=start;
        }
        else
        {
            ptr=start;
            while(ptr->next!=start)
            {
                ptr=ptr->next;
            }
            ptr->next=new_node;
            new_node->next=start;
        }
        printf("\nEnter the data:");
        scanf("%d",&num);
    }
    return start;
}
node * display(node *start)
   {
    node* ptr;
    ptr=start;
    while(ptr->next!=start)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    if(ptr->next==start)
    {
        printf("%d ",ptr->data);
    }
    return start;
}
   node * delete_begin(node *start)
   {
    node *ptr,*ptr1;
    ptr=start;
    ptr1=start;
    while(ptr1->next!=start)
    {
        ptr1=ptr1->next;
    }
    start=start->next;
    free(ptr);
    ptr1->next=start;
    return start;
}
node * delete_after(node *start)
   {
    node *ptr, *preptr;
    ptr=start;
    preptr=ptr;
    int val;
    printf("Enter the element after which the element is to be deleted :");
    scanf("%d",&val);
    while(preptr->data!=val)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=ptr->next;
    free(ptr);
    return start;
}
 node *insertafter(node *start)
   {
    node *new_node,*ptr,*preptr;
    int num, val;
    printf("\nEnter the data: ");
    scanf("%d",&num);
    printf("Enter the value after which the value to be inserted: ");
    scanf("%d",&val);
    new_node=(node *)malloc(sizeof(node));
    new_node->data=num;
    ptr=start;
    preptr=ptr;
    while(ptr->data!=val)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    new_node->next=ptr->next;
    ptr->next=new_node;
    return start;
}
node * insertbegin(node *start)
{
    node *new_node,*ptr;
    int num;
    printf("\nEnter the data :");
    scanf("%d",&num);
    new_node=(node *)malloc(sizeof(node));
    ptr=start;
    new_node->data=num;
    while(ptr->next!=start)
    {
    ptr=ptr->next;
    }
    ptr->next=new_node;
    new_node->next=start;
    start=new_node;
 return start;
}

   node * insertend(node *start)
{
    node *new_node,*ptr;
  int num;
  printf("\n Enter the data :");
  scanf("%d",&num);
  new_node=(node *)malloc(sizeof(node));
  new_node->data=num;
  ptr=start;
    while(ptr->next != start)
    {
        ptr=ptr->next;
    }
    ptr->next=new_node;
    new_node->next=start;
 return start;
}
   node * sort(node *start)
{
    node *ptr1,*ptr2;
  int temp;
  ptr1=start;
  while(ptr1->next !=start)
  {
    ptr2=ptr1->next;
    while(ptr2 !=start)
    {
      if(ptr1->data > ptr2->data)
      {
        temp=ptr1->data;
        ptr1->data=ptr2->data;
        ptr2->data=temp;
      }
      ptr2=ptr2->next;
    }
  ptr1=ptr1->next;
 }
 return start;
}
node * delete_end(node *start)
   {
    node *ptr, *preptr;
    ptr=start;
    while(ptr->next!=start)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=start;
    free(ptr);
    return start;
}
