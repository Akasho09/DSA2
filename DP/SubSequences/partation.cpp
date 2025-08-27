#include <iostream>
using namespace std;

int main (){




}


  bool canPartition(vector<int>& nums) {
        int target  = 0 , n = nums.size(); 

        for(int i=0;i<n;i++) target+=nums[i];

        if(target%2!=0) return false;
        target/=2;

        vector<vector<bool>>dp(n , vector<bool>(target+1, false));

        for(int i=0;i<n;i++) dp[i][0]=true;
        dp[0][nums[0]]=true;

        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                bool notTake = dp[i-1][j];

                bool take = false;
                if(nums[i]<=target) take = dp[i-1][target-nums[i]];

                dp[i][j] = (take | notTake );
            }
        }

        return dp[n-1][target];
    }