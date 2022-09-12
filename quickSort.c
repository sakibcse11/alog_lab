#include<stdio.h>

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a; 
    *a=*b;    
    *b=tmp; 

}
int partition(int arr[],int lb, int ub)
{
    int pivot=arr[lb];
    int start=lb;
    int end=ub;
    while(start<end)
    {
        while(arr[start]<=pivot)
        {
            start++;
        }
        while(arr[end]>pivot)
       {
             end--;
       }
        if(start<end)
        {
            swap(&arr[start],&arr[end]);
        }
    }
    swap(&arr[lb],&arr[end]);
    return end;

}
void quickSort(int arr[],int lb, int ub)
{
    int pLoc;
    if(lb<ub)
    {
        pLoc=partition(arr,lb,ub);
        quickSort(arr,lb,pLoc-1);
        quickSort(arr,pLoc+1,ub);   
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
  
    quickSort(arr, 0, n-1);
  
    printf("\nSorted array is \n");
    printArray(arr, n);
    return 0;
}