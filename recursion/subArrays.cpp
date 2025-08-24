#include <iostream>
using namespace std;

#define MOD 1000000007

    void helper(vector<int>& arr, int r , int& small , int&ans ){
        if(r==arr.size()) return ;
        if(arr[r]<small) { small= arr[r]; }
        ans= (ans+small)%MOD;
        helper(arr, r+1 , small , ans );
    }
    int sumSubarrayMins(vector<int>& arr) {
        int ans = 0; 
        for(int i=0;i<arr.size();i++){
            helper( arr , i , arr[i] , ans );
        }
        return ans ;
    }


    int sumSubarrayMins2(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> st;

        // Step 1: Find left[i] = distance to previous smaller element
        for (int i = 0; i < n; i++) {
            int count = 1;
            while (!st.empty() && arr[st.top()] > arr[i]) {
                count += left[st.top()];
                st.pop();
            }
            left[i] = count;
            st.push(i);
        }

        // clear stack for reuse
        while (!st.empty()) st.pop();

        // Step 2: Find right[i] = distance to next smaller or equal element
        for (int i = n - 1; i >= 0; i--) {
            int count = 1;
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                count += right[st.top()];
                st.pop();
            }
            right[i] = count;
            st.push(i);
        }

        // Step 3: Calculate contributions
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long contrib = (1LL * arr[i] * left[i] * right[i]) % MOD;
            ans = (ans + contrib) % MOD;
        }

        return (int)ans;
    }



int main (){

vector<int> ans = {3,1,2,4};


}


