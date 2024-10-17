#include<stdio.h>
int main()
{
	int n;
	printf("enter the size of the array\n");
	scanf("%d",&n);
	printf("enter the elements of array\n");
       int arr[n];
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	
	
	 for (int i = 1; i < n; i++) {
        arr[i] += arr[i - 1];  
    }
	
	

        for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	
	
	return 0;
}
