#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int queue[MAX];
int rear=-1;
int front=-1;
 
int insertion(); 
int deleted();
int display();
 
 int main()
 {
 	int option;
 	int value;
 	do{
 	printf("1.insert\n");
 	printf("2.delete\n");
 	printf("3.display\n");
 	printf("4.exit\n");

 		printf("enter your choice\n");
 		scanf("%d",&option);
 		
 		switch(option)
 		{
 			case 1:value=insertion();
 			       printf("\n%d is inserted\n",value);
 			       break;
 			
 			case 2:value=deleted();
 			       printf("\n%d is deleted from the queue\n",value);
 			       break;
 			
 			case 3: value=display();
 			        printf("\n%d values are there in the queue\n",value);
 			        break;
 			 }
 			

		 }while(option!=4);


return 0;
}

int deleted()
{
	int del;
	if(front==-1  || front==rear+1)
	{
		printf("empty queue\n");
		exit(1);
	}
	else
	{
		del=queue[front];
		front++;
	}
	return del;
}

int insertion()
{
	int val;
	printf("enter the value you want to insert\n");
	scanf("%d",&val);
	if(front==-1 || rear==-1)
	{
		front=rear=0;
		queue[rear]=val;
		
	}
	else if(rear==MAX-1)
	{
		printf("cannot be inserted\n");
		exit(1);
	}
	else{
		rear++;
		queue[rear]=val;
	}
	return val;
}
 
int display()
{
	
	int count =0;
	printf("queue =\n");
	for(int i=front;i<=rear;i++)
	{
		count++;
		printf(" %d ",queue[i]);
	}
	printf("\n");
	return count;
}
