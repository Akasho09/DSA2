#include <iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n>m) return findMedianSortedArrays(nums2,nums1);
        int half = (n+m)/2;

        int s=0;
        int e = n;

        while(s<=e){
            int i = s+(e-s)/2;

            int j = half - i;
            int left1 = (i==0) ? INT_MIN : nums1[i-1];
            int right1 = (i==n) ? INT_MAX : nums1[i];
            int left2 = (j==0) ? INT_MIN  : nums2[j-1];
            int right2 = (j==m) ? INT_MAX  : nums2[j];

            if(left1<=right2 && right1>=left2){
                if((n+m)%2==0){
                    return (max(left1,left2)+min(right1,right2))/2.00;
                } else {
                    return min(right1,right2);
                }
            } else if (left1>right2) e=i-1;
            else s=i+1;
        }
        return 0.00;
    }
};





int main (){


    
}
