#include <stdio.h>

int jumpSearch(int arr[], int n, int key) {
    int step = 1;  // Set the initial step size

    // Find the block where the key may exist
    int i = 0;
    while (i < n && arr[i] <= key) {
        // Double the index with each iteration
        i = i + step;

        // Update the step size if necessary (you can adjust this logic)
        if (i < n && arr[i] > key) {
            step = i / 2;
        }
    }

    // Perform linear search within the block
    for (int j = i - step; j < i && j < n; j++) {
        if (arr[j] == key) {
            return j;  // Element found
        }
    }

    return -1;  // Element not found
}

int main() {
    int sorted_array[] = {1, 4, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34};
    int array_size = sizeof(sorted_array) / sizeof(sorted_array[0]);
    int target_element = 19;

    int result = jumpSearch(sorted_array, array_size, target_element);
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}