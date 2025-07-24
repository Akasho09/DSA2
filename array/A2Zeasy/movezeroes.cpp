/*
Given an integer array nums, move all 0's to the end of it while 
maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.
*/

#include <iostream>
using namespace std;

    void moveZeroes(vector<int>& nums) {
        int nonZeroes=0;
       for(int i=0;i<nums.size();i++){
        if(nums[i]!=0) nums[nonZeroes++]=nums[i];
       }
       for(nonZeroes;nonZeroes<nums.size();nonZeroes++){
        nums[nonZeroes]=0;
       }
    }

        void moveZeroes2(vector<int>& nums) {
        int nonZeroes=0;
       for(int i=0;i<nums.size();i++){
        if(nums[i]!=0){
            if(i!=nonZeroes){
                swap(nums[i],nums[nonZeroes]);
            }
            nonZeroes++;
        }
       }

    }

int main (){


    
}
