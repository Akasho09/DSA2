/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
*/


#include <iostream>
using namespace std;


    vector<int> majorityElement(vector<int>& nums) {
        int ans = nums[0];
        int count = 1;
        int prev = 0;

        for(int i=0;i<nums.size();i++){
            
            if(count>0){
                if(nums[i]==ans) count++;
                else if(!prev) prev = nums[i];
                else { count--; prev = 0; }
            } else {
                ans = nums[i];
                count = 1;
                prev = 0 ;
            }
        }
        return {ans}; 
    }




int main (){


    
}