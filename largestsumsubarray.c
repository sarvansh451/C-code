#include<stdio.h>

int main() {
    int n;
    printf("Enter the size of the array\n");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
    int largestsum = arr[0];
    
    for (int i = 0; i < n; i++) {
        int sum = 0; 
        for (int j = i; j < n; j++) { 
            sum += arr[j];
            
            if (sum > largestsum) {
                largestsum = sum;
            }
        }
    }

    printf("Largest sum of subarray = %d\n", largestsum);
    return 0;
}

