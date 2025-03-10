#include <stdio.h>
#include <stdlib.h>
#include <time.h>        // for random generation


// swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


int PARTITION(int A[], int p, int r)
{
    int x = A[r];   // Pivot
    int i = p - 1;  // Index of smaller element


    for (int j = p; j <= r - 1; j++)
    {
        if (A[j] <= x)    // If current element is less than or equal to the pivot
        {
            i = i + 1;
            swap(&A[i], &A[j]);  // Swap A[i] and A[j]
        }
    }
    swap(&A[i + 1], &A[r]);
    return i + 1;
}


void QUICKSORT(int A[], int p, int r)
{
    if (p < r)
    {
        int q = PARTITION(A, p, r);   // Divide

        QUICKSORT(A, p, q - 1);  // Left side of pivot
        QUICKSORT(A, q + 1, r);  // Right side of pivot
    }
}


void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}




int main() {
    int size;

    printf("Enter the size of the array: ");
     scanf("%d", &size);


    int A[size];
    srand(time(NULL));  // Seed random number generator

    for (int i = 0; i < size; i++) {
        A[i] = rand() % size + 1;  // Generate number between 1 and size
    }


    printf("\nOriginal array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");



    // ----------------  QuickSort   -------------
    QUICKSORT(A, 0, size - 1);



    printf("\nSorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
