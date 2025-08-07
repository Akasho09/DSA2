#include <iostream>
using namespace std;



    void helper(vector<int>& nums , int i , vector<vector<int>>& ans , vector<int>currSet){
        ans.push_back(currSet);
        if(i==nums.size()) return ;
        for(int j=i;j<nums.size();j++){
            currSet.push_back(nums[j]);
        helper(nums , j+1 , ans , currSet );
            currSet.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans ;
        vector<int>v ;
        helper(nums , 0 , ans , v);
        return ans ;
    }


    


int main (){

    
}