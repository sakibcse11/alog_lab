// Counting sort in C programming

#include <stdio.h>

void countingSort(int array[], int n) {
  int tArr[n];
  int max = array[0];
  for (int i = 1; i < n; i++) {
    if (array[i] > max)
      max = array[i];
  }
  int count[max+1];

  // Initialize count array with all zeros.
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  // Store the count of each element
  for (int i = 0; i < n; i++) {
    count[array[i]]++;
  }

  // Store the cummulative count of each array
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  // Find the index of each element of the original array in count array, and
  // place the elements in tArr array
  for (int i = n - 1; i >= 0; i--) {
    tArr[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  // Copy the sorted elements into original array
  for (int i = 0; i < n; i++) {
    array[i] = tArr[i];
  }
}
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
  
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
  
    printf("Given array is \n");
    printArray(arr, n);
  
    countingSort(arr, n);
  
    printf("\nSorted array is \n");
    printArray(arr, n);
    return 0;
}