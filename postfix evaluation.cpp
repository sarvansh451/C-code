#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100

char postfix[MAX];
char stack[MAX];
int top=-1;

void push(int val)
{
	if(top==MAX-1)
	{
		printf("stack is full\n");
	}
	top++;
	stack[top]=val;
}
int pop()
{
	int value;
	if(top==-1)
	{
		printf("stack is empty\n");
	}
	value=stack[top];
	top--;
	return value;
}

int postfixevaluation()
{
	int i,a,b;
	for(int i =0;i<strlen(postfix);i++){
	if(postfix[i]>='0'&&postfix[i]<='9')
	{
		push(postfix[i] - '0');
	}
	else
	{
		a=pop();
		b=pop();
		switch(postfix[i]){
			case '+': push(b+a);
			break;
			case '-': push(b-a);
			break;
			case '*': push(b*a);
			break;
			case '/': push(b/a);
			break;
			case '^': push(pow(b,a));
			break;
		}
	}

	}
	return pop();
}

int main()
{
	printf("enter the postfix term\n");
	gets(postfix);
	int result;
	result=postfixevaluation();
	printf("calculated term=\n");
	printf("%d\n",result);
	return 0;
}
