/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing
 a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. 
If you cannot achieve any profit, return 0.
*/

#include <iostream>
using namespace std;

   int maxProfit(vector<int>& prices) {
    int min =INT_MAX;
    int ans = 0 ;

    for(int i=0;i<prices.size();i++){
        if(prices[i]<min) min = prices[i];
        if(prices[i]-min>ans) ans = prices[i]-min ;
    }

    return ans;
    }

        int maxProfit2(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int ans = 0;
        int b=0;
        int s=1;
        while(s<prices.size()){
            if(prices[s]-prices[b]>=0) {
                ans=max(prices[s]-prices[b],ans);
                s++;
                }
            else { b=s; s++; }
        }
        return ans ;
    }

int main (){


    
}