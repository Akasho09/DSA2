#include <iostream>
using namespace std;

bool possSol(vector<int> &nums, int k, int m) {
    int lastPos = nums[0];
    k--;  // One cow placed at the first stall
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] - lastPos >= m) {
            k--;
            lastPos = nums[i];  // Place cow at current stall
        }
        if(k == 0) return true;  // All cows placed
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k) {
    int n = stalls.size();
    if(n == 1) return 0;

    sort(stalls.begin(), stalls.end());  // Sort the stalls!

    int s = 0;
    int e = stalls[n - 1] - stalls[0];  // Maximum possible distance
    int ans = 0;

    while(s <= e) {
        int m = s + (e - s) / 2;
        if(possSol(stalls, k, m)) {
            ans = m;
            s = m + 1;  // Try for a bigger minimum distance
        } else {
            e = m - 1;
        }
    }

    return ans;
}




int main (){


    
}
