/*
Given an array nums containing n distinct numbers in the range [0, n], 
return the only number in the range that is missing from the array.


*/

#include <iostream>
using namespace std;

    int missingNumber(vector<int>& nums) {
        int xorNum = 0 ;
        for(int i=1;i<=nums.size();i++){
            xorNum^=i;
        }
        for(int i=0;i<nums.size();i++){
            xorNum^=nums[i];
        }
        return xorNum;
    }


int main (){

vector<int> nums = {1,2,3,7,6,0,4};

    cout<< missingNumber(nums);

cout<<endl;
    
}