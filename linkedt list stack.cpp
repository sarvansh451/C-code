#include<stdio.h>
#include<stdlib.h>
//stacks using linked list//
struct stack
{
int data;
struct stack *next;
};
struct stack *top = NULL;
struct stack *push(struct stack *, int);
struct stack *display(struct stack *);
struct stack *pop(struct stack *);
int main()
{
	int val;
	int choice;
	do{
	printf("menu\n");
	printf("1.push data\n");
	printf("2.pop\n");
	printf("3.display\n");
	printf("4.exit\n");
	printf("enter your choice\n");
	scanf("%d",&choice);
	switch(choice){
  	case 1:
printf("\n Enter the number to be pushed on stack: ");
scanf("%d", &val);
top = push(top, val);
break;

       case 2:
top = pop(top);
break;

       case 3:
top = display(top);
break;
}

}while(choice != 4);
return 0;	
}
struct stack *display(struct stack *top)
{
	if(top==NULL)
	{
		printf("stack underflow\n");
	}
	struct stack *ptr=top;
	printf("stack=\n");
	while(ptr->next!=NULL)
	{
		printf("%d->",ptr->data);
		ptr=ptr->next;
	}
	printf("%d\n",ptr->data);
	return top;
}

struct stack *push(struct stack *top, int val)
{
	
		struct stack *newnode=(struct stack*)malloc(sizeof(struct stack));
		newnode->data=val;
		newnode->next=NULL;
		newnode->next=top;
		top=newnode;
		
}

struct stack *pop(struct stack *top){
	if(top==NULL)
	{
		printf("stack underflow\n");
	}
	struct stack *ptr=(struct stack*)malloc(sizeof(struct stack));
	ptr=top;
	top=top->next;
	free(ptr);
	return top;
}
