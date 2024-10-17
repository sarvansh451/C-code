#include<stdio.h>

void reversearray(int arr[], int n, int i) {
   
    if (i >= n/2) {
        return;
    }
    
    
    int temp = arr[i];
    arr[i] = arr[n-i-1];
    arr[n-i-1] = temp;
    
   
    reversearray(arr, n, i + 1);
}



int main()
{
	 int n;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int i=0;
    reversearray(arr,n,i);
      printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
    return 0;
}
