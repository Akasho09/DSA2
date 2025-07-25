#include <iostream>
using namespace std;



    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>count ;

        for(int i=0;i<nums.size();i++){
            if(count.find(nums[i])!=count.end()){
                count[nums[i]]++;
            } else if(count.find(nums[i]-1)!=count.end()) count[nums[i]-1]++;
            else if(count.find(nums[i]+1)!=count.end()) count[nums[i]+1]++;
        }
    }


int main (){


    
}