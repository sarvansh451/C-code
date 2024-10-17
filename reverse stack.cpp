#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int arr[MAX];
int top=-1;
int stack1[MAX];
void reverse();
void display();
void push(int item);
int pop();
void insertatbottom(int x);
void reversestack();
int k,j;
int isEmpty() {
    return (top == -1);
}
int isFull() {
    return (top == MAX - 1);
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    display();
    reversestack();
    display();
    return 0;
}
void push(int item) {
    if (isFull()) {
        printf("stack is full, cannot insert.\n");
        return;
    }
    top++;
    stack1[top]=item;
}

int pop() {
    int item;
    if (isEmpty()) {
        printf("Queue is empty, cannot delete.\n");
        exit(1);
    }
   item=stack1[top];
   top--;
   return item;
}
    
void display() {
    int i;
    if (isEmpty()) {
        printf("stack is empty.\n");
        return;
    }
    for (i = top; i >=0; i--) {
        printf("%d ", stack1[top]);
    }
    printf("\n");
}
 void reversestack()
 {
 	if(!isEmpty)
 	{
 		int x=stack1[top];
 		pop();
 		reversestack();
 		insertatbottom(x);
	 }
 }
 
 void insertatbottom(int x)
 {
 	while(!isEmpty)
 	{
 		k=0;
 		arr[k]=pop();
 		k++;
 		
	 }
	 push(x);

	 while(j=k;j>=0;j--)
	{
		push(arr[j]);
	}

 }
