#include <iostream>
using namespace std;

int main (){



}

    int bs (vector<int>& v , int num){
        int s = 0 ;
        int e = v.size()-1;

        while(s<e){
            int m = s+(e-s)/2;
            if(v[m]<num) s=m+1;
            else e=m;
        }

        return s ;
    }
    int lengthOfLIS3(vector<int>& nums) {
        int n = nums.size();
        vector<int>v;

        for(int num : nums){
            if(v.empty() || v.back()<num){
                v.push_back(num);
            } else {
                int i = bs(v , num);
                v[i]=num;
            }
        }

        return v.size();
    }   

    int lengthOfLIS2(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n , 1);
        int ans = 1;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i], 1+dp[j]);
                }
            }
            ans = max(ans , dp[i]);
        }

        return ans ;
    }

    int helper(vector<int>& nums , int p , int c , vector<vector<int>> &dp){
        if(c==nums.size()) return 0;
        if(dp[p+1][c]!=-1) return dp[p+1][c];

        int notTake = helper(nums, p, c + 1 , dp);
        int take = 0;
        if (p == -1 || nums[c] > nums[p]) {
            take = 1 + helper(nums, c, c + 1 , dp);
        }
        return dp[p+1][c] = max(take , notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1 , vector<int>(n,-1));
        return helper( nums , -1 , 0 , dp);
    }
