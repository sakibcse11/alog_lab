#include <stdio.h>

int max(int a, int b) {
   return (a > b)? a : b;
}

int rodCutting(int price[], int n) {    //from price and length of n, find max profit
   int profit[n+1];
   profit[0] = 0;
   int maxProfit;

   for (int i = 1; i<=n; i++) {
      maxProfit = 0;    //initially set as -ve infinity
      for (int j = 0; j < i; j++)
         maxProfit = max(maxProfit, price[j] + profit[i-j-1]);
      profit[i] = maxProfit;
   }
   return maxProfit;
}

int main() {
   int priceList[] = {1, 5, 8, 9, 10, 17, 17, 20};
   int rodLength = 8;
   int maxProfit;
    maxProfit= rodCutting(priceList, rodLength);
    printf("maximum Profit= %d",maxProfit);
}