#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1] if they are in the wrong order
                swap(&arr[j], &arr[j + 1]);
            }
        }
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

    // Perform bubble sort
    bubbleSort(arr, MAX);

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