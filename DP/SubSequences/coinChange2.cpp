#include <iostream>
using namespace std;

int main (){



}

    int helper(int amount, vector<int>& coins , int i , vector<vector<int>>&dp ){
        if(amount==0) return 1;
        if(i==coins.size()) return 0;

        if(dp[i][amount]!=-1) return dp[i][amount];
        int NotTake = helper( amount , coins , i+1 , dp);
        int take = 0 ;
        if(coins[i]<=amount) take = helper( amount-coins[i] , coins , i , dp);

        return dp[i][amount]=take+NotTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1 , -1));
        return helper( amount , coins , 0 , dp);
    }


    int change2(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int x = coin; x <= amount; x++) {
                dp[x] = (0LL + dp[x] + dp[x - coin]) % INT_MAX;
            }
        }

        return (int)dp[amount];
    }