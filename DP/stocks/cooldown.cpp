#include <iostream>
using namespace std;

int main (){



}




    int helper(vector<int>& prices , int i , bool buy , vector<vector<int>>& dp){
        if(i>=prices.size()) return 0 ;

        if(dp[i][buy]!=-1) return dp[i][buy];
        int p ;
        if( !buy ){
            p = max(helper( prices , i+1 , false , dp ), helper( prices , i+1  , true , dp)-prices[i]);
        } else {
            p = max(helper( prices , i+1  , true , dp), prices[i] + helper( prices , i+2 , false , dp ));
        }
        return dp[i][buy] = p ;
    }
    int maxProfit2(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n , vector<int>(2, -1));
        return helper(prices , 0 , false   , dp);
    }




    class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0 ;

        vector<int>hold(n ,0 );
        vector<int>sold(n ,0 );
        vector<int>cool(n ,0 );

        hold[0]=-prices[0];
        for(int i=1;i<n;i++){
            hold[i]=max(hold[i-1] , cool[i-1]-prices[i]);
            sold[i]=hold[i-1]+prices[i];
            cool[i]=max(cool[i-1], sold[i-1]);
        }

        return max(sold[n-1], cool[n-1]);
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0 ;
        int ind = 0 ;
        for(int i=1;i<n;i++){
            if(prices[i]<prices[i-1]){
                int a = 0 ;
                if(i>1) a = prices[i-1]-prices[i-2];
                int b = 0 ;
                if(i<n-1) b = prices[i+1]-prices[i]; 
                if(a>=b) {
                    ans+=(prices[i-1]-prices[ind]);
                    ind = i+1;
                } else {
                    ans+=(prices[i-2]-prices[ind]);
                    ind = i;
                }
            }
                cout <<ind <<endl;
        }

        if(ind<n && prices[n-1]>prices[ind]) ans+=(prices[n-1]-prices[ind]);
        return ans ;
    }
};