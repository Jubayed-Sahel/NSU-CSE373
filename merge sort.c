#include <stdio.h>
#include <limits.h> // For INT_MAX
#include <math.h>    // For floor()
#include <stdlib.h>  // For rand() and srand()
#include <time.h>    // For time()


//Combine part of the merge sort
void merge(int A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1 + 1], R[n2 + 1]; // Create extra space for sentinels


    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[q + 1 + j];

    // Sentinels (∞) to avoid boundary checks
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;


    int i = 0, j = 0;

    for (int k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}


// Main Mergesort
void mergeSort(int A[], int p, int r) {
    if (p < r) {
            int q = floor((p + r) / 2); // Divide
            mergeSort(A, p, q);    // Conquer Left Subsequence
            mergeSort(A, q + 1, r); // Conquer Right Subsequence
            merge(A, p, q, r);      // Combine
    }
}

//  print array
void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}


int main() {
    int size;


    printf("Enter the size of the array: ");
     scanf("%d", &size);        // uncomment to insert inpu size

    // Seed the random number generator
    srand(time(NULL));


    int A[size];

    // Generate random numbers
    for (int i = 0; i < size; i++) {
        A[i] = rand() % size + 1;  // Generates numbers between 1 and 'size'
    }


    printf("\nOriginal array: \n");
    printArray(A, size);


    mergeSort(A, 0, size - 1);


    printf("\nSorted array: \n");
    printArray(A, size);

    return 0;
}
