#include <iostream>
using namespace std;

class Solution {

    void helper(vector<int>& candidates, int target , vector<int>currVec , vector<vector<int>>&ans , int i){
       if(target==0){
        ans.push_back(currVec);
        return; 
       } 

       for(int j=i;j<candidates.size();j++){
        if(j>i && candidates[j]==candidates[j-1]) continue;
        if (candidates[j] > target) break;

        currVec.push_back(candidates[j]);
        helper(candidates , target-candidates[j] , currVec , ans , j+1);
        currVec.pop_back();

       }

    }

public:

     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans ;
        vector<int>currVec;
        helper(candidates , target , currVec , ans , 0);
        return ans ;
     }

};


int main (){

    
}