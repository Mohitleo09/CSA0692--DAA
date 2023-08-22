#include <stdio.h>
#include <time.h>
void bubbleSort(int arr[], int n) {
    int temp,i,j;
    for ( i = 0; i < n - 1; i++) {
        for ( j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main() {
    int n,i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for ( i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    clock_t start = clock();
    bubbleSort(arr, n);
    clock_t end = clock();
    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Sorted array:\n");
    for ( i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTime taken by Bubble Sort: %f seconds\n", timeTaken);
    return 0;
}
