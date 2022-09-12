#include<stdio.h>
void insertionSort(int arr[], int n)
{
    int i,j,temp;
    for (i=1; i<n; i++)
    {
        temp=arr[i];
        j=i-1;
        while (j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
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
  
    insertionSort(arr, n);
  
    printf("\nSorted array is \n");
    printArray(arr, n);
    return 0;
}
