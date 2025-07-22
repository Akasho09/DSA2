/*
Given an array nums of size n which may contain duplicate elements, 
return a list of pairs where each pair contains a unique element from the array and its frequency in the array.

You may return the result in any order, but each element must appear exactly once in the output.
*/



#include <iostream>
#include <map>
using namespace std;

   vector<vector<int>> countFrequencies(vector<int>& nums) {
        map<int, int> count;

        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }

        vector<vector<int>> ans;
        for (auto it : count) {
            ans.push_back({it.first, it.second});
        }

        return ans;
    }


    int mostFrequentElement(vector<int>& nums) {

        unordered_map<int, int>count ;
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
        }

        int maxi = INT_MIN;
        int ans = -1;
        for(auto i : count){
            if(i.second>maxi){
                ans=i.first;
                maxi = i.second ;
            }
        }
        return ans;
    }

int main (){

vector<int> nums = {1,2,3,1,2,3,4,1,2,6,5,1,5,2,2};
    vector<vector<int>> v2 = countFrequencies(nums);
    for(int i=0;i<v2.size();i++){
    for(int j=0;j<v2[0].size();j++){
    cout <<v2[i][j] << " ";
    }
    cout <<endl;
}

cout << mostFrequentElement(nums);

}