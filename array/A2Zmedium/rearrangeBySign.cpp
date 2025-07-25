/*
You are given a 0-indexed integer array nums of even length consisting of an equal number of 
positive and negative integers.

You should return the array of nums such that the the array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.
*/

#include <iostream>
using namespace std;

    vector<int> rearrangeArray(vector<int>& nums) {
      queue<int>q;
      int lasNum = -1;  
      int index=0;

      for(int i=0;i<nums.size();i++){
     if (!q.empty() && ((lasNum > 0 && q.front() < 0) || (lasNum < 0 && q.front() > 0))) {
            nums[index++]=q.front();
            lasNum=q.front();
             q.pop(); i--;
        }
        else if ( ((lasNum<0 && nums[i]>0) || ( lasNum>0 && nums[i]<0)) ) {
            lasNum=nums[i];
            nums[index++]=nums[i];
        }
        else {
            q.push(nums[i]);
        }
      } 

      if(!q.empty()) nums[nums.size()-1]=q.front();
      return nums; 
    }

        // Separate positive and negative numbers

    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;

        for (int num : nums) {
            if (num > 0) pos.push_back(num);
            else neg.push_back(num);
        }

        vector<int> result;
        for (int i = 0; i < pos.size(); i++) {
            result.push_back(pos[i]);
            result.push_back(neg[i]);
        }

        return result;
    }

    int main (){


    
}