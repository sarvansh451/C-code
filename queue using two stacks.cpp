#include<stdio.h>
#include<stdlib.h>
#define MAX 4


int stack1[MAX];
int stack2[MAX];
int top1=-1;
int top2=-1;
 void push();
 void pop();
 void display();
 
 
int main()
{
 int val,option;


 do
 {
        printf("\n****MAIN MENU****");
        printf("\n 1. push an element");
        printf("\n 2. pop an element");
        printf("\n 3. Display the queue");
        printf("\n 4. EXIT");
        printf("\n Enter your option");
        scanf("%d",&option);

        switch(option)
        {

           case 1:

      
               push();
               break;


           case 2:
        
               pop();
               break;


           case 3:

               display();
               break;

          
        }
    
    }while(option !=4);
     
     return 0;
}
void push()
{
	int num;
	printf("enter the value you want to insert\n");
	scanf("%d",&num);
	if (top1==MAX-1)
	{
		printf("queue is full\n");
	}
	else
	{
		top1++;
		stack1[top1]=num;
		printf("inserted\n");
	}

}


void pop()
{
	if(top1==-1)
	{
		printf("no element\n");
		
	}
	else{
	while(top1!=-1)
	{
		top2++;
		stack2[top2]=stack1[top1];
		top1--;
	}
	top2--;
		while(top2!=-1)
	{
		top1++;
		stack1[top1]=stack2[top2];
		top2--;
	}
	printf("deleted\n");
	}
	
}

void display()
{
	if(top1==-1)
	{
		printf("empty queue\n");
	}
	else
	{
		for(int i=0;i<=top1;i++)
		{
			printf("%d ",stack1[i]);
		}
		printf("\n");
	}
}



