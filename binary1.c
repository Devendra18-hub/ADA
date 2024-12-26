#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variable to count the number of comparisons
//long long comparisons = 0;

// Binary Search function
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
       // comparisons++;  // Increment comparison count
        
        int mid = low + (high - low) / 2;

        // Check if the target is present at mid
        if (arr[mid] == target) {
            return mid;  // Target found at index mid
        }

        // If target is smaller than mid, search in the left half
        if (arr[mid] > target) {
            high = mid - 1;
        }
        // If target is larger than mid, search in the right half
        else {
            low = mid + 1;
        }
    }

    return -1;  // Target not found
}

// Utility function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to generate a sorted array for testing
/**void generateSortedArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i * 2;  // Generate sorted elements, e.g., 0, 2, 4, 6, ...
    }
}**/
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;

    // Traverse through all array elements
    for (i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted array
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}


int main() {
    srand(time(NULL));  // Seed the random number generator

    // Define the size of the array
    int n = 10000;  // You can change this size for different inputs
    int arr[n];
    for(int i=0;i<n;i++){
		arr[i]=rand()%1000;
	}

    // Generate a sorted array of integers
    //generateSortedArray(arr, n);
    selectionSort(arr,n);

    printf("Sorted array (first 10 elements):\n");
    printArray(arr, 10);  // Print only the first 10 elements for preview

    // Choose a target element to search for
    int target = rand()%1000;  // Generate a random target number in the range

    printf("\nSearching for target: %d\n", target);

    // Reset the comparison counter
    //comparisons = 0;

    // Perform Binary Search and measure the time taken
    clock_t start = 0;
    int result = binarySearch(arr, n, target);
    clock_t end = clock();

    // Calculate the time taken in seconds
    double time_taken = ((double)(end - start)) / CLK_TCK;

    if (result != -1) {
        printf("Target found at index: %d\n", result);
    } else {
        printf("Target not found\n");
    }

    printf("\nSearch statistics:\n");
   // printf("Comparisons: %lld\n", comparisons);
    printf("Time taken: %.6f seconds\n", time_taken);

    return 0;
}
