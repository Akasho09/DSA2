/*
ans is the index till the array is valid , keep updating it till no 3 are same.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int n = nums.size();
       if(n<3) return n;
       int ans = 2;
       for(int i=2;i<n;i++){
        if(nums[i]!=nums[ans-2]){
            if(i!=ans) nums[ans]=nums[i];
            ans++; 
       }
       } 
       return ans ;
    }
};

int main (){


    
}