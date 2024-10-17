#include <stdio.h>
#include <stdlib.h>

// Structure to represent a non-zero element in the matrix
struct Element {
    int value;
    int row;
    int col;
    struct Element* next;
};

// Function to create a new non-zero element
struct Element* createElement(int value, int row, int col) {
    struct Element* newElement = (struct Element*)malloc(sizeof(struct Element));
    if (newElement == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newElement->value = value;
    newElement->row = row;
    newElement->col = col;
    newElement->next = NULL;
    return newElement;
}

// Function to insert a non-zero element into the linked list
void insertElement(struct Element** head, int value, int row, int col) {
    struct Element* newElement = createElement(value, row, col);
    if (*head == NULL) {
        *head = newElement;
    } else {
        struct Element* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newElement;
    }
}

// Function to display the sparse matrix
void displaySparseMatrix(struct Element* head, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (head != NULL && head->row == i && head->col == j) {
                printf("%d ", head->value);
                head = head->next;
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

// Main function
int main() {
    int m, n, k;
    printf("Enter the number of rows, columns, and non-zero elements: ");
    scanf("%d %d %d", &m, &n, &k);

    struct Element* sparseMatrix = NULL;

    printf("Enter the non-zero elements (value row col):\n");
    for (int i = 0; i < k; i++) {
        int value, row, col;
        scanf("%d %d %d", &value, &row, &col);
        insertElement(&sparseMatrix, value, row, col);
    }

    printf("Sparse Matrix:\n");
    displaySparseMatrix(sparseMatrix, m, n);

    return 0;
}
