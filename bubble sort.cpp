#include<stdio.h>
#include<stdlib.h>
int n;
int temp;
int k;

 void print(int arr[])
 {
 	for(int i=0;i<n;i++)
 	{
 		printf("%d ",arr[i]);
	 }
 }
int main()
{

	printf("enter the size of the array\n");
	scanf("%d",&n);
	int arr[n];
	printf("enter the all the elements\n")
	 
	  for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("enter the kth largest element you want to find\n");
	scanf("%d",&k);

	 for(int i=0;i<n;i++)
	 {
	 	for(int j=0;j<n-i;j++)
	 	{
	 		if(arr[j]>arr[j+1])
	 		{
	 			temp=arr[j];
	 			arr[j]=arr[j+1];
	 			arr[j+1]=temp;
	 			
			 }
			 
			 
		 }
		 if(i==k)
		 {
		 	printf("largest element=%d\n",arr[n-i-1]);
		 	break;
		 }
		 
	  } 
	
	
	return 0;
}
