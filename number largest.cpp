#include<stdio.h>
int main()
{
	int n;
	int arr[n];
	printf("enter the size of the array\n");
	scanf("%d",&n);
	printf("enter the elements of the array\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		
	}
	//largesr element//
	int largest=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]>largest)
		{
			largest=arr[i];
		}
		
	}
	printf("%d",largest);
	return 0;
	
	
}
