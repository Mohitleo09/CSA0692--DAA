#include <stdio.h>  
int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;      
}   
int main() {  
  int a[] = {11, 14, 25, 30, 40, 41, 52, 57, 70};   
  int target = 40;  
  int n = sizeof(a) / sizeof(a[0]); 
  int res = binarySearch(a, 0, n-1, target);  
  printf("The elements of the array are - ");  
  for (int i = 0; i < n; i++)  
  printf("%d ", a[i]);   
  printf("\nElement to be searched is - %d", target);  
  if (res == -1)  
  printf("\nElement is not present in the array");  
  else  
  printf("\nElement is present at %d position of array", res);  
  return 0;  
} 
