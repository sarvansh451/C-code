#include<stdio.h>
#include<stdlib.h>

int n, temp, k;

void print(int arr[]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    printf("Enter the size of the array:\n");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter all the elements:\n");
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the k-th largest element you want to find:\n");
    scanf("%d", &k);

    // Bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    printf("Sorted array: ");
    print(arr);
    
    if (k <= n) {
        printf("The %d-th largest element is: %d\n", k, arr[n - k]);
    } else {
        printf("Invalid k: %d is larger than the array size.\n", k);
    }
    
    return 0;
}
