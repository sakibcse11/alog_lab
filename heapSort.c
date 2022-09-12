#include<stdio.h>

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a; 
    *a=*b;    
    *b=tmp; 

}
void maxHeapify(int arr[],int n, int i)
{
    int large=i;
    int l=(2*i)+1;
    int r=(2*i)+2;
    while (l<n && arr[l]>arr[large])
    {
        large=l;
    }
    while (r<n && arr[r]>arr[large])
    {
        large=r;
    }
    if(large!=i)
    {
        swap(&arr[i],&arr[large]);
        maxHeapify(arr,n,large);
    }

}
void heapSort(int arr[],int n)
{
    int i;
    for( i=n/2-1;i>=0;i--)
    {
        maxHeapify(arr,n,i);
    }
    for(i=n-1; i>=0;i--)
    {
        swap(&arr[0],&arr[i]);
        maxHeapify(arr,i,0);
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
  
    heapSort(arr, n);
  
    printf("\nSorted array is \n");
    printArray(arr, n);
    return 0;
}