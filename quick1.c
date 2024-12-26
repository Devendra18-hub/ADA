#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1;       

   
    for (int j = low; j < high; j++) {
       
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

   
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;  
}


void quicksort(int arr[], int low, int high) {
    if (low < high) {
        
        int pi = partition(arr, low, high);

        
        quicksort(arr, low, pi - 1);  
        quicksort(arr, pi + 1, high); 
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 20000;  
    }
}

int main() {
    //srand(time(0));  
    int n = 90000; 
    int arr[n];
    generateRandomArray(arr, n);

    printf("Original array (first 10 elements):\n");
    printArray(arr, 10); 
    clock_t start = clock();
    quicksort(arr, 0, n - 1);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLK_TCK;

    printf("\nSorted array (first 10 elements):\n");
    printArray(arr, 30);  

    printf("\nSorting statistics:\n");
    printf("Time taken: %.6f seconds\n", time_taken);

    return 0;
}
