#include <iostream>
using namespace std;

int main (){




}


class Solution {
public:
    int helper(vector<int>& nums , int i  ,  int t , int&ans , int sum , int els ,vector<vector<int>>&dp){
        if(els==nums.size()/2){
            int diff = t-sum ;
            diff*=2;
            if(diff<0) diff*=-1;
            ans = min ( ans , diff);
            return diff ;
        }
        if(i>=nums.size()) return INT_MAX;
        if(dp[els][sum]) return dp[els][sum];
     return dp[els][sum] = min(helper(nums , i+1 , t, ans ,  sum+nums[i] , els+1 , dp) ,helper(nums , i+1 , t , ans , sum , els, dp) ) ;
    }
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int sum  = 0 ;
        int maxS = 0;
        for(int i=0;i<nums.size();i++) {
            sum+=nums[i];
            if(sum>maxS) maxS=sum;
        }
        int ans =  INT_MAX ;
        vector<vector<int>>dp(n , vector<int>( maxS , -1 ));
        helper(nums , 0 , sum/2 , ans , 0 , 0 , dp); 
        return ans ;
    }
};