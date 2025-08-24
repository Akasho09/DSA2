#include <iostream>
using namespace std;

int main (){




}


class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        stack<int>st ;
        int n = nums.size();
        vector<int>ans(n,0);
        vector<int>maxims(n,0);
        int maxi = nums[0];
        for(int i=0;i<n;i++){
            if(nums[i]>maxi) maxi=nums[i];
            maxims[i]=maxi;
        }
        int minInd = 0; 
        vector<int>minInds(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]<nums[minInd]) minInds[i]=minInd;
            else minInds[i]=i;
        }

        int minii = n-1;
        maxi = 0;
        for(int i=n-1;i>=0;i--){
            if(minInds[i]<minii) {
                minii=minInds[i];
                maxi=maxims[i];
            }
            if(i>=minii && maxims[i]<maxi){
                maxims[i]=maxi;
            }
        }

        return maxims;
    }
};©leetcode