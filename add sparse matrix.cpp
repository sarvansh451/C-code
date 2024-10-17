#include <stdio.h>

// Structure to represent a triplet (row, column, value)
struct Triplet {
    int row, col, value;
};

// Function to read a sparse matrix
void readSparseMatrix(struct Triplet matrix[], int *rows, int *cols, int *numElements) {
    printf("Enter the number of rows, columns, and non-zero elements: ");
    scanf("%d %d %d", rows, cols, numElements);
    
    printf("Enter the elements in triplet format (row, column, value):\n");
    for (int i = 0; i < *numElements; i++) {
        scanf("%d %d %d", &matrix[i].row, &matrix[i].col, &matrix[i].value);
    }
}

// Function to add two sparse matrices
void addSparseMatrices(struct Triplet matrix1[], struct Triplet matrix2[], int rows, int cols, int numElements1, int numElements2) {
    int resultSize = 0;
    struct Triplet result[numElements1 + numElements2];
    
    int i = 0, j = 0, k = 0;
    while (i < numElements1 && j < numElements2) {
        if (matrix1[i].row < matrix2[j].row || (matrix1[i].row == matrix2[j].row && matrix1[i].col < matrix2[j].col)) {
            result[k] = matrix1[i];
            i++;
        } else if (matrix1[i].row > matrix2[j].row || (matrix1[i].row == matrix2[j].row && matrix1[i].col > matrix2[j].col)) {
            result[k] = matrix2[j];
            j++;
        } else {
            result[k] = matrix1[i];
            result[k].value += matrix2[j].value;
            i++;
            j++;
        }
        k++;
    }

    // Copy any remaining elements from both matrices
    while (i < numElements1) {
        result[k] = matrix1[i];
        i++;
        k++;
    }
    while (j < numElements2) {
        result[k] = matrix2[j];
        j++;
        k++;
    }

    resultSize = k;

    printf("Resultant Matrix:\n");
    printf("%d %d %d\n", rows, cols, resultSize);
    for (int l = 0; l < resultSize; l++) {
        printf("%d %d %d\n", result[l].row, result[l].col, result[l].value);
    }
}

int main() {
    struct Triplet matrix1[100], matrix2[100];
    int rows1, cols1, numElements1, rows2, cols2, numElements2;
    
    printf("Enter sparse matrix-1:\n");
    readSparseMatrix(matrix1, &rows1, &cols1, &numElements1);
    
    printf("Enter sparse matrix-2:\n");
    readSparseMatrix(matrix2, &rows2, &cols2, &numElements2);
    
    if (rows1 != rows2 || cols1 != cols2) {
        printf("Matrix dimensions do not match. Addition not possible.\n");
    } else {
        addSparseMatrices(matrix1, matrix2, rows1, cols1, numElements1, numElements2);
    }

    return 0;
}
