#include <iostream>
using namespace std;

   vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>>ans ;

        for(int i=0;i<n-3;i++){
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for(int j=i+1;j<n-2;j++){
        if (j > i + 1 && nums[j] == nums[j - 1]) continue; 
            int s = j+1;
            int e = n-1;
                long long prevSum = nums[i]+nums[j];
            while(s<e){
                long long sum = prevSum+nums[s]+nums[e];
                if(sum==target) {
                    ans.push_back({nums[i] , nums[j] , nums[s] , nums[e] });
                    while(s<e && nums[s]==nums[s+1]) s++;
                    while(s<e && nums[e]==nums[e-1]) e--;
                    s++; e--;
                } else if (sum>target) e--;
                else s++;
            }
        }
        }

        return ans ;
    }

int main (){


    
}