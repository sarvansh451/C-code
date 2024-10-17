#include<stdio.h>
int main()
{
	int n;
	printf("enter the size of the array\n");
	scanf("%d",&n);
	int arr[n];
	printf("enter the elements of the array\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	//logic of most repeated term//
	int count;
	int maxcount=0;
	int number;
	for(int i=0;i<n;i++)
	
	{
		count=0;
		
		
		for(int j=0;j<n;j++)
		{
			if(arr[i]==arr[j]){
				count++;
			}
			
		}
		if(count>maxcount)
		{
			maxcount=count;
			
			number=arr[i];
		}
		
		
	}
	printf("number which is most repeated = %d\n",number);
	printf("number repeated =%d",maxcount);
		
	
}
