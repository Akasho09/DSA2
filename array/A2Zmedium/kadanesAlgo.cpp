/*
Given an integer array nums, find the subarray with the largest sum, 
and return its sum.
*/

#include <iostream>
using namespace std;

vector<int> maxSubArrayPrint(vector<int>& nums) {
    int sum = 0;
    int ans = INT_MIN;
    int start = 0, ansL = 0, ansR = 0;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];

        if (sum > ans) {
            ans = sum;
            ansL = start;
            ansR = i;
        }

        if (sum < 0) {
            sum = 0;
            start = i + 1;
        }
    }

    return {ansL, ansR};
}

int maxSubArray(vector<int>& nums) {

    int sum = 0 ;
    int ans = INT_MIN;

    for(int i=0;i<nums.size();i++) {
        sum+=nums[i];
        if(sum<0){
            ans= max(sum,ans);
            sum = 0;
        } else if(sum>ans){
            ans=sum;
        }
    }
    return ans ;
}


// Given an integer array arr, find the contiguous subarray (containing at least one number) which
// has the largest sum and returns its sum and prints the subarray.



int main (){

vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    vector<int>v = maxSubArrayPrint(nums);
for(int i=0;i<v.size();i++){
    cout <<v[i] << " ";
}
cout<<endl;

    
}