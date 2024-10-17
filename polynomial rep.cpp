#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	int coef;
	struct node* next;
};
void create(struct node* head){
	int num;
	printf("how many number of polynomials are there in the linked list\n");
	scanf("%d",&num);
	struct node* ptr=(struct node*)malloc(sizeof(struct node));
	struct node* p=(struct node*)malloc(sizeof(struct node));
	ptr=head;
	if(ptr->next==NULL)
	{
		printf("enter the linked list number 1\n");
        	scanf("%d %d",ptr->data,ptr->coef);
		ptr=ptr->next;
	}
	int index=2;
	while(index!=num+1)
	{
		struct node* q=(struct node*)malloc(sizeof(struct node));
		struct node* q1=(struct node*)malloc(sizeof(struct node));
		
		printf("enter the linked list number %d\n",index);
		scanf("%d %d",q->data,q->coef);
		q1=q->next;
		if(index==num)
		{
			q->next=NULL;
			break;
		}
		index++;
	}

	printf("\n");
	p=head;
		while(ptr!=NULL)
	{
		printf("%dx^%d ",ptr->data,ptr->coef);
		ptr=ptr->next;
		if(ptr!=NULL)
		{
			printf("+");
		}
		else
		{
			printf("\n");
		}
		
	}
	
	
}
int main(){
      struct node* head=(struct node*)malloc(sizeof(struct node));
      head->next=NULL;
      create(head);

return 0;
}

