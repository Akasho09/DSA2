/*
Problem Statement: Given an array containing both positive and negative integers, 
we have to find the length of the longest subarray with the sum of all elements 
equal to zero.
*/

/*
✅ Approach (Efficient - O(n) time, O(n) space)
Idea:

We maintain a running prefix sum while traversing the array.

If at any point the prefix sum is zero, the subarray from index 0 to current index has sum zero.

If the prefix sum has been seen before, it means the subarray between the previous index and the current one has sum zero.

We store the first occurrence of each prefix sum in a hash map.
*/
#include <iostream>
using namespace std;

        int maxLength(vector<int>& nums) {
            
        int ans = 0;
        int pSum = 0;
        unordered_map<int , int > map;
        for(int i=0;i<nums.size();i++){
            pSum+=nums[i];

            if(pSum==0) ans=i+1;

            if(map.find(pSum)!=map.end()){
                ans = max(ans , i-map[pSum]);
            } else {
                map[pSum]=i;
            }

        }

        return ans ;
    }

int main (){


    
}
