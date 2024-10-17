#include <stdio.h>

void exchange(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}


void rotateright(int arr[], int num) {
    for (int i = num - 1; i > 0; i--) {
        exchange(&arr[i], &arr[i - 1]);
    }
}

int main() {
    int n;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int num;
    printf("Enter the number of elements to be rotated right: ");
    scanf("%d", &num);
    
   
    
    
    rotateright(arr, num);
    
    printf("The elements of the array after rotation:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}

