#include <iostream>
using namespace std;


int main (){




}


    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        int ind = 0;
        for(int i=0;i<n;i++){
            if(nums[i]>nums[ind]) ind = i ;
        }

        int k = 0 ;
        vector<int>nge(n,-1);
        stack<int>st;
        while(k<n){
            while(!st.empty() && st.top()<=nums[ind]) st.pop();
            if(!st.empty()) nge[ind]=st.top();
            st.push(nums[ind]);
            ind--; k++;
            if(ind<0) ind=n-1;
        }
        return nge;
    }