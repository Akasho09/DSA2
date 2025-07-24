/*
Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. 
If no such sub-array exists, return 0.
*/

#include <iostream>
using namespace std;

// sliding window for +ve and 0s array only
    int longestSubarray(vector<int> &nums, int k){
        int l=0;
        int r=0;
        int sum = nums[l];
        int ans = 0;

        while(r<nums.size()){   

            while(l<=r && sum>k) {
                sum-=nums[l++];
            }
            if (sum==k){ ans=max(ans,r-l+1);} 
            
  
            if(r < nums.size()) sum+=nums[++r];

        }
        return ans ;
    }


    // for -ves and 0 
    int longestSubarray2(const vector<int>& nums, int k) {
        unordered_map<int,int> prefixSumMap;
        int maxLen = 0;
        int sum =0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==k){
                maxLen= max(maxLen,i+1);
            }

            int rem = sum-k;
            if(prefixSumMap.find(rem)!=prefixSumMap.end()){
                int len = i-prefixSumMap[rem];
                maxLen= max(maxLen,len);
            }

            if(prefixSumMap.find(sum)==prefixSumMap.end()){
                prefixSumMap[sum]=i;
            }
        }


    return maxLen;
}

int main (){

vector<int> nums = {-3, 2, 1 , 3};
cout << longestSubarray2(nums , 6) <<endl;


vector<int> nums2 = { 2, 1 , 3, 0 , 1};
cout << longestSubarray(nums2 , 6);


}