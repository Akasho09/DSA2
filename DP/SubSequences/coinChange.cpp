#include <iostream>
using namespace std;

int main (){



}


    int coinChange2(vector<int>& coins, int amount) {
        
        vector<int>dp(amount+1, INT_MAX);
        int n = coins.size();
        for(int i=1;i<=amount;i++){
            for(int i=0; i<n ; i++){
                if(amount - coins[i] >= 0 ){
                    dp[i]=min(dp[i] , dp[amount - coins[i]]+1);
                }
            }
        }

        return dp[amount]==INT_MAX ? -1 : dp[amount] ;
    }


#include <iostream>
using namespace std;

int main (){



}

class Solution {
public:
    int helper(vector<int>& coins, int amount , int sum , int ind , int c , int&ans , vector<vector<int>>&dp ) {
       if(sum>=amount || ind==coins.size()){
        if(sum==amount){
            ans = min(ans , c);
             return ans;
        }
        return INT_MAX;
       }
       if(dp[])
        for(int i=ind;i<coins.size();i++){
            if() helper(coins , amount , sum + coins[i] , i , c+1 , ans );
        }
        return ;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = INT_MAX ;
        helper(coins , amount , 0 , 0 , 0 , ans , dp);
        if(ans == INT_MAX) return -1;
        return ans ;
    }
};