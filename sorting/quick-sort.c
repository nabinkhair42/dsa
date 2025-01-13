#include <stdio.h>
int i,j;
// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int *A, int low, int high) {
    int pivot = A[high]; // Choose the last element as pivot
    int *i = &A[low - 1]; // Pointer for the smaller element (initially before the array)
    for (int *j = &A[low]; j < &A[high]; j++) { // j iterates through the array
        if (*j < pivot) { // If current element is smaller than pivot
            i++;
            swap(i, j); // Swap elements
        }
    }
    swap(i + 1, &A[high]); // Place pivot in the correct position
    return (i + 1) - A; // Return pivot index as an integer
}

// Quick Sort function
void quickSort(int *A, int low, int high) {
    if (low < high) {
        int pi = partition(A, low, high);

        // Recursively sort elements before and after partition
        quickSort(A, low, pi - 1);
        quickSort(A, pi + 1, high);
    }
}

// Function to print an array
void printArray(int *A, int size) {
    for (int *ptr = A; ptr < A + size; ptr++) {
        printf("%d ", *ptr);
    }
    printf("\n");
}

// Main function
int main() {
    int A[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Unsorted array: ");
    printArray(A, n);

    quickSort(A, 0, n - 1);

    printf("Sorted array: ");
    printArray(A, n);

    return 0;
}




