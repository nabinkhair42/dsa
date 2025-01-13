#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void bubbleSort(int A[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int i, A[200000], n;
    printf("Enter Value of n (max 200000): ");
    scanf("%d", &n);

    if (n > 200000)
    {
        printf("Error: n exceeds maximum allowed size (200000).\n");
        return 1;
    }

    srand(time(NULL));

    // Fill the array with random numbers
    for (i = 0; i < n; i++)
    {
        A[i] = rand(); 
    }

    printf("Array before sorting:\n");
    display(A, n);

    // Measure sorting time
    clock_t start = clock();
    bubbleSort(A, n);
    clock_t end = clock();

    printf("Array after sorting:\n");
    display(A, n);

    // Calculate and display time taken
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d elements: %f seconds\n", n, time_taken);

    return 0;
}
