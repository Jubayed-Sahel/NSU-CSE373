#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


// swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


void MaxHeapify(int A[], int i)
{
    extern int heapSize;  // Global Function Extern
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;


    if (left < heapSize && A[left] > A[largest])
        largest = left;


    if (right < heapSize && A[right] > A[largest])
        largest = right;


    if (largest != i)
    {
        swap(&A[i], &A[largest]);
        MaxHeapify(A, largest);
    }
}


void BuildMaxHeap(int A[], int length)
{
    extern int heapSize;     // Global Function Extern
    heapSize = length;


    for (int i = (int)floor((length / 2) - 1); i >= 0; i--)
    {
        MaxHeapify(A, i);
    }
}


void HeapSort(int A[], int length)
{
    extern int heapSize;
    BuildMaxHeap(A, length);  // Convert array to max heap

    for (int i = length - 1; i > 0; i--)
    {
        swap(&A[0], &A[i]);  // Swap max element with the last
        heapSize--;           // Reduce heap size by 1
        MaxHeapify(A, 0);     // Restore heap property
    }
}


void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int heapSize = 0;              // Global heap size variable


int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int A[size];      // max 10000000 size an array can afford

    srand(time(0)); // Seed the random number generator with the current time


    for (int i = 0; i < size; i++) {
        A[i] = rand() % size + 1;  // Generate numbers between 1 and 'size'
    }

    printf("\nOriginal array:\n");
    printArray(A, size);

    HeapSort(A, size);                      //------------------  Heap Sort the array  -----------------

    printf("\nSorted array:\n");
    printArray(A, size);

    return 0;
}
