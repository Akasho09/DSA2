/*
Problem Statement: Given an array of integers A and an integer B. 
Find the total number of subarrays having bitwise XOR of all elements equal to k.
*/



#include <iostream>
using namespace std;

// Prefix XOR
// map
    long subarrayXor(vector<int> &nums, int k) {
        long ans = 0;
        int preXor=0;
        unordered_map<int,int>map;
        map[preXor]++; //setting the value of 0.
        
        for(int i=0;i<nums.size();i++){
            preXor^=nums[i];

            int x = preXor^k;

            ans+=map[x];

            map[preXor]++;

        }
        return ans;
    }



int main (){


    
}
