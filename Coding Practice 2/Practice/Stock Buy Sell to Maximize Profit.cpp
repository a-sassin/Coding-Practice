// Program to find best buying and selling days
#include <bits/stdc++.h>

using namespace std;

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int *, int);

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, i;
        cin >> n;
        int price[n];
        for (i = 0; i < n; i++) cin >> price[i];
        // function call
        stockBuySell(price, n);
    }
    return 0;
}

// User function template for C++

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n) {
    // code here
    // Prices must be given for at least two days
    if (n == 1)
        return;
 
    // Traverse through given price array
    int i = 0,count=0;
    while (i < n - 1) {
 
        // Find Local Minima
        // Note that the limit is (n-2) as we are
        // comparing present element to the next element
        while ((i < n - 1) && (price[i + 1] <= price[i]))
            i++;
 
        // If we reached the end, break
        // as no further solution possible
        if (i == n - 1)
            break;
 
        // Store the index of minima
        int buy = i++;
 
        // Find Local Maxima
        // Note that the limit is (n-1) as we are
        // comparing to previous element
        while ((i < n) && (price[i] >= price[i - 1]))
            i++;
 
        // Store the index of maxima
        int sell = i - 1;
        
         if(sell!=buy){
               cout<<"("<<buy<<" "<<sell<<")"<<" ";
               count++;
           }

    }
    if(count==0)
        cout<<"No Profit";
    cout<<endl;
}


void stockBuySell(int price[], int n) {
    // code here
    int profit=0;
    for(int i=1;i<n;i++){
        if(price[i]>price[i-1]){
            profit += price[i] - price[i-1];
        }
    }
    cout<<profit;
}

void stockBuySell(int price[], int n) {
    // code here
    int maxProfit = 0;
    int minSoFar = price[0];
    for(int i=0;i<n;i++){
        minSoFar = min(minSoFar,price[i]);
        int profit = price[i] - minSoFar;
        maxProfit = max(maxProfit,profit);
    }
    cout<<maxProfit;
}