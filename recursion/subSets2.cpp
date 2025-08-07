

#include <iostream>
using namespace std;

class Solution {
    void helper(vector<int>& nums , vector<int>v , vector<vector<int>>& ans , int i){
        ans.push_back(v);
        if(i==nums.size()) return ;

        for(int j=i;j<nums.size();j++){
        if(j>i && nums[j]==nums[j-1]) continue;

        v.push_back(nums[j]);
        helper(nums , v , ans , j+1);
        v.pop_back();
        
        }
    }
public:
     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans ;
        vector<int>v;
        helper(nums , v , ans , 0);
        return ans ;
    }
};

int main (){

    
}