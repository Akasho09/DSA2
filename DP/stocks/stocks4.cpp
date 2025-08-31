#include <iostream>
using namespace std;

int main (){



}

    int helper(int k, vector<int>& prices , int i , int buy , vector<vector<vector<int>>> &dp){
        if(i==prices.size() || k==0) return 0 ;

        if(dp[i][buy][k-1]!=-1) return dp[i][buy][k-1];
        int profit ;
        if(buy){
            profit= max( helper(k  , prices , i+1 , 1 , dp) , helper(k  , prices , i+1 , 0 , dp)-prices[i] );
        } else {
            profit= max( helper(k  , prices , i+1 , 0 , dp ) , helper(k-1  , prices , i+1 , 1 , dp)+prices[i]);
        }

        return dp[i][buy][k-1] = profit;
    }
    int maxProfit2(int k, vector<int>& prices) {
        int n = prices.size();
        if(k>n/2) k=n/2;
        vector<vector<vector<int>>>dp (n ,  vector<vector<int>>(2 ,  vector<int>(k , -1)));
        return helper(k  , prices , 0 , 1 , dp);
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(k>n/2) k=n/2;
        vector<int>b(k+1 , INT_MIN);
        vector<int>s(k+1 , 0);

        for(int i : prices){
            for(int j=1;j<=k;j++){
                b[j]=max(b[j],s[j-1]-i);
                s[j]=max(s[j],b[j]+i);
            }
        }

        return s[k] ;
    }