/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

*/

#include <iostream>
using namespace std;

    int majorityElement(vector<int>& nums) {
        int ans = nums[0];
        int count = 1;

        for(int i=1;i<nums.size();i++){
            if(count>0){
            if(nums[i]==ans) count++;
            else count--;
            }
            else {
                ans = nums[i];
                count = 1;
            }
        }
        return ans ;
    }

int main (){


    
}
