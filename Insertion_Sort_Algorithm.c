#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;


        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;


    printf("Enter the size of the array: ");
    scanf("%d", &size);


    int arr[size];

    // Initialize random number generator
    srand(time(NULL));

    // Generate random numbers between 1 and size
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % size + 1;
    }

    printf("\nOriginal array: \n");
    printArray(arr, size);

    insertionSort(arr, size);

    printf("\nSorted array: \n");
    printArray(arr, size);

    return 0;
}
