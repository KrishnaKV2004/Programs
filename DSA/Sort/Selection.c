#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n) {
    int i, j, minIndex;

    for (i = 0; i < n - 1; i++) {
        // Find the minimum element in the unsorted part of the array
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        swap(&arr[minIndex], &arr[i]);
    }
}

int main() {
    int *arr;

    // Dynamically allocate memory for the array
    arr = (int *)malloc(MAX * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input elements into the array
    printf("Enter %d elements for the array:\n", MAX);
    for (int i = 0; i < MAX; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform selection sort
    selectionSort(arr, MAX);

    // Display the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < MAX; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free allocated memory
    free(arr);

    return 0;
}