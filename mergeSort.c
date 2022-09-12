#include<stdio.h>
void merge(int arr[],int lb, int mid, int ub)
{
    int i=lb;
    int j=mid+1;
    int k=lb;
    int tArr[ub+1];
    while(i<=mid && j<=ub)
    {
        if(arr[i]<=arr[j])
        {
            tArr[k]=arr[i];
            i++;
        }
        else
        {
            tArr[k]=arr[j];
            j++;
        }
        k++;
    }
    if (i>mid)
    {
        while(j<=ub)
        {
            tArr[k]=arr[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<=mid)
        {
            tArr[k]=arr[i];
            i++;
            k++;
        }
    }

    for(k=lb; k<=ub; k++)
    {
        arr[k]= tArr[k];
    }
}
void mergeSort(int arr[],int lb, int ub)
{
    int mid;
    if(lb<ub)
    {
        mid=(lb+ub)/2;
        mergeSort(arr,lb,mid);
        mergeSort(arr,mid+1,lb);
        merge(arr,lb,mid,ub);
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
  
    mergeSort(arr, 0, n-1);
  
    printf("\nSorted array is \n");
    printArray(arr, n);
    return 0;
}