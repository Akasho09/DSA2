/*
✅ Approach: Two Pointers after Sorting
Sort the array.

Loop through the array with index i and fix one number.

Use two pointers (left and right) to find pairs such that nums[i] + nums[left] + nums[right] == 0.

Skip duplicates for i, left, and right to ensure unique triplets.
*/

#include <iostream>
using namespace std;

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        vector<vector<int>>ans ;
        for(int i=0;i<nums.size()-2;i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int s  = i+1;
            int e = nums.size()-1;
            while(s<e){
            if((nums[s]+nums[e]+nums[i])==0) {
                ans.push_back({nums[i],nums[s],nums[e]});
                while (s < e && nums[s] == nums[s + 1]) s++;
                while (s < e && nums[e] == nums[e - 1]) e--;
                 s++; e--;
            } else if((nums[s]+nums[e]+nums[i])>0) e--;
              else s++;
            }
        }
        return ans ;
    }

int main (){


    
}
