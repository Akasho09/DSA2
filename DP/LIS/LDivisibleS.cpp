#include <iostream>
using namespace std;

int main (){



}

   vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());

        vector<int>dp(n , 1) , hash(n,0);
        int len = 0 , ind = 0 ;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[j]>=dp[i] ){
                        dp[i]=dp[j]+1;
                        hash[i]=j;
                    }
            }
            if(dp[i]>len) {
                len = dp[i]; ind = i ;
            }
        }

        vector<int>ans ;
        ans.push_back(nums[ind]);
        
        while(hash[ind]!=ind){
            ind = hash[ind];
            ans.push_back(nums[ind]);
        }

        return ans ;
    }