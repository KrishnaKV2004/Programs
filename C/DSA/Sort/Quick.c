#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    // Perform quicksort
    quickSort(arr, 0, MAX - 1);

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