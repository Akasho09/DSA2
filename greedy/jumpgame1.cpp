#include <iostream>
using namespace std;


int main (){




}

    bool canJump(vector<int>& nums) {
        int high = 0;
        int n = nums.size();

        int i=0;
        while(i<n){
            if(high>=i){
                high=max(high,i+nums[i]);
            }
            i++;
            if(high>=n-1) return true;
        }

        return false;
    }