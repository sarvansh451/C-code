#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary using recursion
void decimalToBinary(int n, char *binaryStr, int *index) {
    if (n == 0) {
        return;
    }
    
    decimalToBinary(n / 2, binaryStr, index);
    
    binaryStr[(*index)++] = (n % 2) + '0';
}

// Function to process the input file and write binary values to the output file
void convertNumbersToBinary(const char *inputFilename, const char *outputFilename, int n) {
    FILE *inputFile = fopen(inputFilename, "r");
    FILE *outputFile = fopen(outputFilename, "w");

    if (inputFile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }
    
    if (outputFile == NULL) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    int number;
    int count = 0;
    char binaryStr[17]; // To hold binary representation with maximum 16 bits + null terminator
    int index;

    while (fscanf(inputFile, "%d", &number) != EOF && count < n) {
        index = 0;
        
        // Convert number to binary
        decimalToBinary(number, binaryStr, &index);
        
        // Pad binary string with leading zeros
        while (index < 16) {
            binaryStr[index++] = '0';
        }
        binaryStr[index] = '\0';
        
        // Reverse the binary string
        for (int i = 0; i < index / 2; i++) {
            char temp = binaryStr[i];
            binaryStr[i] = binaryStr[index - i - 1];
            binaryStr[index - i - 1] = temp;
        }
        
        fprintf(outputFile, "The binary equivalent of %d is %s\n", number, binaryStr);
        count++;
    }

    fclose(inputFile);
    fclose(outputFile);
}

// Function to display the content of the output file
void displayOutput(const char *outputFilename) {
    FILE *outputFile = fopen(outputFilename, "r");

    if (outputFile == NULL) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    char ch;
    while ((ch = fgetc(outputFile)) != EOF) {
        putchar(ch);
    }

    fclose(outputFile);
}

int main() {
    // Define the values directly
    int n = 4; // Number of decimal numbers to process
    const char *inputFilename = "numbers.dat";  // Input file containing decimal numbers
    const char *outputFilename = "binarydata.dat"; // Output file to store binary values

    convertNumbersToBinary(inputFilename, outputFilename, n);
    displayOutput(outputFilename);

    return 0;
}

