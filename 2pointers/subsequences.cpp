

#include <iostream>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    int numSubseq(vector<int>& nums, int target) {
        int ans = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());

    vector<int> pow2(n, 1);
    for (int i = 1; i < n; ++i) {
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    }

        int s = 0;
        int e = n-1;

        while(s<=e){
            if(nums[s]+nums[e]<=target){
                ans = (ans+pow2[e-s])%MOD;
                s++;
            } else e--;
        }

        return ans ;
    }
};


int main (){

    
}