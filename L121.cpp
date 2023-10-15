// 121. Best Time to Buy and Sell Stock - done with common approch [took more run time problem]
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    cout<<"Array is\n";
    for (int i = 0; i < prices.size(); i++)
        cout<<prices[i]<<" ";   cout<<'\n';

    // int min = prices[0],max = prices[0];
    // int minIndex = 0,maxIndex = 0;
    int profit = 0;

    for (int i = prices.size()-1; i>0 ; i--){
        for (int j = i-1; j>=0; j--){
            if(prices[i]-prices[j]>0){
                if (prices[i]-prices[j]>profit)                
                    profit = prices[i]-prices[j];
            }
        }
    }
    return profit;
}

int main(){
    vector<int> a = {7,1,5,3,6,4};    // profit - 5
    // vector<int> a = {7,6,4,3,1};     // profit - 0
    // vector<int> a = {2,4,1};        // profit - 2
    
    // vector<int> a = {5,6,46,2,8,9,1,5,8,9,7};  // profit - 40
    cout<<"Max profit can be = "<<maxProfit(a);
    return 0;
}

/*  I saw this solution
int maxProfit(vector<int>& prices) {
       int min_price = prices[0];
        int maxprof = 0;

        for(int i=1;i<prices.size();i++){
            maxprof = max(maxprof,prices[i]-min_price);
            min_price = min(prices[i],min_price);
        }

        return maxprof;
    }
}*/