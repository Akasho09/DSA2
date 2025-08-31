#include <iostream>
using namespace std;

int main (){



}



class Solution {
public:
    int maxProfit(vector<int>& prices){
        int buy1 = INT_MIN , buy2=INT_MIN;
        int sell1 = 0 ,sell2 = 0 ;

        for(int p : prices) {
            buy1 = max(buy1 , -p);
            sell1 = max(sell1 , buy1+p);
            buy2 = max(buy2 , sell1-p);
            sell2 = max(sell2 , buy2+p);
        }
        return sell2;
    }
};

int helper(vector<int>& prices , int n, int ind, int buy, int cap, vector<vector<vector<int>>>& dp){
        if(ind==n || cap==0) return 0 ;

        if (dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

        int profit =0;
        if(buy==0){
        profit = max( helper(prices, n, ind + 1, 0, cap, dp),
                    helper(prices, n, ind + 1, 1, cap, dp)-prices[ind]);
        } else {
        profit = max(helper(prices, n, ind + 1, 1, cap, dp),
                     prices[ind] + helper(prices, n, ind + 1, 0, cap - 1, dp));
        }
        return dp[ind][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices){
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return helper(prices , n , 0 , 0 , 2  , dp);
    }