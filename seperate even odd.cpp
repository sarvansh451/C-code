#include<stdio.h>
int main()
{
	int n;
	int arr[n];
	printf("enter the size of the array\n");
	scanf("%d",&n);
	printf("enter the elements of array\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	//seperate odd and even number//
	int index=0;

	for(int i=0;i<n;i++)
	{
		if(arr[i]%2==0)
		{
			int temp=arr[index];
			arr[index]=arr[i];
			arr[i]=temp;
			index++;	
		}
	
	
	}
	
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	
	
	
}
