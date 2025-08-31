#include <iostream>
using namespace std;

int main (){



}

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n == 0) return 0;

        int hold = -prices[0]; // profit when holding a stock
        int cash = 0;          // profit when not holding

        for (int i = 1; i < n; i++) {
            hold = max(hold, cash - prices[i]);            // buy or keep holding
            cash = max(cash, hold + prices[i] - fee);      // sell or keep cash
        }

        return cash;
    }
};


class Solution {
public:
    int helper(vector<int>& prices, int fee , bool buy , int i ,  vector<vector<int>> & dp){
        if(i==prices.size()) return 0 ;

        if(dp[i][buy]!=-1) return dp[i][buy]; 
        int p ;
        if(buy){
        p = max( helper(prices , fee , true , i+1 , dp) , helper(prices , fee , false , i+1 , dp)-prices[i]);
        } else {
        p = max( helper(prices , fee , false , i+1 , dp) , helper(prices , fee , true , i+1, dp)+prices[i]-fee);
        }

        return dp[i][buy] = p ;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp (n ,  vector<int>(2, -1 )) ;
        return helper(prices , fee , true , 0 , dp );
    }
};