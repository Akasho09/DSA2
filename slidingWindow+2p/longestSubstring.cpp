
#include <iostream>
using namespace std;

    int lengthOfLongestSubstring(string s) {
        vector<int>arr(128,-1);
        int n = s.size();
        int ans = 0;
        int ind = -1;
        for(int i=0;i<n;i++){
            ans=max(ans,i-ind-1);
            if(arr[s[i]]!=-1) ind = max(arr[s[i]],ind);
            arr[s[i]]=i;
        }
        ans=max(ans,n-ind-1);
        return ans;
    }


int main (){

    
}