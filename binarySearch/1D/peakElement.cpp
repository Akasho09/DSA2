#include <iostream>
using namespace std;

    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int s = 0 ;
        int e = n-1;
        int m = s+(e-s)/2;

        while(s<e){
             m = s+(e-s)/2;
             if(nums[m]>nums[m+1]) e=m;
             else s=m+1;
        }

        return s;
    }


int main (){

    string s = "ak";
    string s2 = "ka";

    
}
