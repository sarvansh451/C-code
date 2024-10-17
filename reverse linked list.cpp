#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
void reverse(struct node* head){
struct node* temp1=(struct node*)malloc(sizeof(struct node));
struct	node* temp2=(struct node*)malloc(sizeof(struct node));
struct	node* ptr=(struct node*)malloc(sizeof(struct node));
temp1=NULL;
temp2=NULL;
while(head!=NULL)
{
	temp2=head->next;
	head->next=temp1;
	temp1=head;
	head=temp2;
	
}
head=temp1;
ptr=head;
 printf("\n reverse linked list =\n");
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;	
	}


}


	
int main()
{
struct node* head=(struct node*)malloc(sizeof(struct node));
      struct	node* second=(struct node*)malloc(sizeof(struct node));
      struct node* third=(struct node*)malloc(sizeof(struct node));
      struct node* fourth=(struct node*)malloc(sizeof(struct node));
	
	head->data=1;
	head->next=second;
	second->data=2;
	second->next=third;
	third->data=3;
	third->next=fourth;
	fourth->data=4;
	fourth->next=NULL;

	reverse(head);
	return 0;
}
