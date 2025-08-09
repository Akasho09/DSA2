
#include <iostream>
using namespace std;


// counting bits 3multiples 
   int singleNumber(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < 32; i++) {
            int c = 0;
            for (int num : nums) {
                if (num & (1LL << i)) c++;
            }
            if (c % 3 != 0) {
                ans |= (1LL << i);
            }
        }
        return ans;
    }

    // sorting 
    int singleNumber2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(nums[0]!=nums[1]) return nums[0];
        for(int i=1;i<n;i+=3){
            if(nums[i]!=nums[i-1]) return nums[i-1];
        }
        return nums[n-1];
    }

    // buckets
    int singleNumber3(vector<int>& nums) {
        int ones = 0;
        int twos = 0;
        for(int i=0;i<nums.size();i++){
            ones = (ones^nums[i]) & (~twos);
            twos = (twos^nums[i]) & (~ones);
        }
        return ones ;
    }



int main (){

    
}