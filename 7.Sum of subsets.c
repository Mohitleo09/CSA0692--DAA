#include <stdio.h>
void printSubset(int subset[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("\n");
}
void subsetSum(int set[], int n, int subset[], int subsetSize, int targetSum, int currentIndex) {
    if (targetSum == 0) {
        printSubset(subset, subsetSize);
        return;
    }
    if (currentIndex == n) {
        return;
    }
    subset[subsetSize] = set[currentIndex];
    subsetSum(set, n, subset, subsetSize + 1, targetSum - set[currentIndex], currentIndex + 1);
    subsetSum(set, n, subset, subsetSize, targetSum, currentIndex + 1);
}
int main() {
    int set[] = {6, -4, 7, -1, 5, 2, 8, 1};
    int n = sizeof(set) / sizeof(set[0]);
    int targetSum = 10;
    int subset[20]; 
    printf("Subsets with sum %d:\n", targetSum);
    subsetSum(set, n, subset, 0, targetSum, 0);
    return 0;
}
