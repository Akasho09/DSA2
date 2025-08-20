#include <iostream>
using namespace std;



    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st ;
        int n = nums2.size() , m = nums1.size();
        vector<int>nge(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]) st.pop();
                if(!st.empty()) nge[i]=st.top();
                st.push(nums2[i]);
        }

        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            if(nge[i]!=-1) mpp[nums2[i]]=nge[i];
        }

        vector<int>ans(m,-1);
        for(int i=0;i<m;i++){
            if(mpp[nums1[i]]) ans[i]=mpp[nums1[i]];
        }

        return ans;
    } 

int main (){

    vector<int> nums1 = {};
    vector<int> nums2 = {1,3,4,2};
nextGreaterElement(nums1 , nums2);


}
