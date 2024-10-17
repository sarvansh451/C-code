#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;	
};
struct node *head=NULL;
struct node* ptr1=head;;
struct node* ptr2=NULL;

void display();
void insert();


void insertpriority(int num)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	newnode->next=NULL;
	
	if(head==NULL)
	{
	
		head=newnode;
	}else
	{
		
	 while (ptr1 != NULL && num > ptr1->data) {
            ptr2 = ptr1;
            ptr1 = ptr1->next;
        }
        if (ptr2 == NULL) {
            // Insert at the beginning
            newnode->next = head;
            head = newnode;
        }
        else {
            // Insert at the appropriate position
            ptr2->next = newnode;
            newnode->next = ptr1;
        }
    }
}

void display()
{
	printf("priority queue=\n");
	if(head==NULL)
	{
		printf("empty\n");
		exit(1);
	}
	else
	{
	struct node* ptr3=head;
	while(ptr3!=NULL)
	{
		printf("%d ",ptr3->data);
		ptr3=ptr3->next;
	}
	printf("\n");
	}
	exit(1);
}
void insert()
{
	
	int num;
	printf("\nenter the number you want to insert according to the priority\n");
	printf("press -1 to display and exit\n");
	scanf("%d",&num);
	if(num==-1)
	{
		display();
	}
	insertpriority(num);
	
}
int main()
{
   insert();
   return 0;
}
