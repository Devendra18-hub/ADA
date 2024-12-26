#include<stdio.h>

void findsubset(int arr[], int n, int sum, int index, int current[], int current_size)
{
    // If the sum becomes zero, print the current subset
    if (sum == 0)
    {
        for (int i = 0; i < current_size; i++)
        {
            printf("%d ", current[i]);
        }
        printf("\n");
        return;
    }

    // If we reach the end of the array, return
    if (index == n)
    {
        return;
    }

    // Include the current element and move to the next index
    current[current_size] = arr[index];
    findsubset(arr, n, sum - arr[index], index + 1, current, current_size + 1);

    // Exclude the current element and move to the next index
    findsubset(arr, n, sum, index + 1, current, current_size);
}

void subsetsum(int arr[], int n, int sum)
{
    int current[n];
    findsubset(arr, n, sum, 0, current, 0);
}

int main()
{
    int n, sum;
    printf("Enter the number of Elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements in array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the sum of subset: ");
    scanf("%d", &sum);

    printf("Subset sum %d:\n", sum);
    subsetsum(arr, n, sum);
    return 0;
}
