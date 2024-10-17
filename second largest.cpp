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
	
	//second largest and second smallest//
	
	

	for(int i = 0; i <n-1; i++) {
    for(int j = 0; j < n-i-1; j++) {
        if(arr[j] > arr[j+1]) {
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
    }
}

          for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\nsecond largest number=%d",arr[n-2]);
	printf("\nsecond smallest number=%d",arr[1]);
	return 0;
	
}
