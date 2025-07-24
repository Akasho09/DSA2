/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.
*/


#include <iostream>
using namespace std;

 int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int n = nums.size();
        int ans = 0;
        unordered_map<int , int > preMap ;
        preMap[0] = 1; // Important: base case for subarray starting at index 0

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];

            if(preMap.find(sum-k)!=preMap.end()) ans += preMap[sum - k];

            preMap[sum]++;

        }
        return ans ;
    }


    

int main (){


    
}

