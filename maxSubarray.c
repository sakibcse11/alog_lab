#include <stdio.h>

// function to return maximum number among three numbers
int maximum(int a, int b, int c)
{
  if (a>=b && a>=c)
    return a;
  else if (b>=a && b>=c)
    return b;
  return c;
}

// function to find maximum sum of subarray crossing the middle element
int max_crossing_subarray(int ar[], int low, int mid, int high)
{
  /*
    Initial left_sum should be -infinity.
    One can also use INT_MIN from limits.h
  */
  int left_sum = -1000000;
  int sum = 0;
  int i;

  /*
    iterating from middle
    element to the lowest element
    to find the maximum sum of the left
    subarray containing the middle
    element also.
  */
  for (i=mid; i>=low; i--)
  {
    sum = sum+ar[i];
    if (sum>left_sum)
      left_sum = sum;
  }

  /*
    Similarly, finding the maximum
    sum of right subarray containing
    the adjacent right element to the
    middle element.
  */
  int right_sum = -1000000;
  sum = 0;

  for (i=mid+1; i<=high; i++)
  {
    sum=sum+ar[i];
    if (sum>right_sum)
      right_sum = sum;
  }

  /*
    returning the maximum sum of the subarray
    containing the middle element.
  */
  return (left_sum+right_sum);
}

// function to calculate the maximum subarray sum
int max_sum_subarray(int ar[], int low, int high)
{
  if (high == low) // only one element in an array
  {
    return ar[high];
  }

  // middle element of the array
  int mid = (high+low)/2;

  // maximum sum in the left subarray
  int maximum_sum_left_subarray = max_sum_subarray(ar, low, mid);
  // maximum sum in the right subarray
  int maximum_sum_right_subarray = max_sum_subarray(ar, mid+1, high);
  // maximum sum in the array containing the middle element
  int maximum_sum_crossing_subarray = max_crossing_subarray(ar, low, mid, high);

  // returning the maximum among the above three numbers
  return maximum(maximum_sum_left_subarray, maximum_sum_right_subarray, maximum_sum_crossing_subarray);
}

int main()
{
  int a[] = {3, -1, -1, 10, -3, -2, 4};
  printf("%d\n", max_sum_subarray(a, 0, 6));
  return 0;
}