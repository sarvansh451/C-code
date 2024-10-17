#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	int coef;
	struct node* next;
};
int main(){
     
      struct node* head=(struct node*)malloc(sizeof(struct node));
      struct	node* second=(struct node*)malloc(sizeof(struct node));
      struct node* third=(struct node*)malloc(sizeof(struct node));
      struct node* fourth=(struct node*)malloc(sizeof(struct node));
	struct node* p=(struct node*)malloc(sizeof(struct node));
	p=head;
	head->data=5;
	head->coef=7;
	head->next=second;
	second->data=-3;
	second->coef=5;
	second->next=third;
	third->data=1;
	third->coef=2;
	third->next=fourth;
	fourth->data=9;
	fourth->coef=0;
	fourth->next=NULL;
	
	while(p!=NULL)
	{
		printf("%dx^%d ",p->data,p->coef);
		p=p->next;
		if(p!=NULL)
		{
			printf("+");
		}
		else
		{
			printf("\n");
		}
		
	}
	
return 0;
}

