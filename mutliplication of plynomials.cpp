#include <stdio.h>
void multiply(int arr1[],int arr2[],int result[],int n,int m)
{
	for(int i=0;i<=m+n;i++)
	{
		result[i]=0;
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			result[i+j]+=arr1[i]*arr2[j];
		}
	}
	printf("\nmultiplication of polynomial=\n");
		for(int j=0;j<=m+n;j++)
		{
			printf("%dx^%d ",result[j],j);
		
		}
			
		
}
int main()
{
	int n,m;
	int arr1[n],arr2[m];
	printf("enter the highest power of the first polynomial \n");
	scanf("%d",&n);
	printf("enter the highest power of the second polynomial \n");
	scanf("%d",&m);
	printf("enter the elements of the first polynomial\n");
	for(int i=0;i<=n;i++)
	{
		printf("x^%d ",i);
		scanf("%d",&arr1[i]);
	}
	printf("\nenter the elements of the Second polynomial\n");
	for(int i=0;i<=m;i++)
	{
		printf("x^%d ",i);
		scanf("%d",&arr2[i]);
	}
	printf(" first polynomial 1=\n");
		for(int i=0;i<=n;i++)
	{
	printf("%dx^%d ",arr1[i],i);
	}
	printf("\nsecond polynomial=\n");
		for(int i=0;i<=m;i++)
	{
	printf("%dx^%d ",arr2[i],i);
	}
	int result[m+n];
	multiply(arr1,arr2,result,n,m);
	return 0;
}

