/*
Problem Statement: You're given an sorted array arr of n integers and an integer x. 
Find the floor and ceiling of x in arr[0..n-1].
The floor of x is the largest element in the array which is smaller than or equal to x.
The ceiling of x is the smallest element in the array greater than or equal to x.
*/

class Solution {
  public:
    int findFloor(vector<int>& nums, int x) {
        int s = 0, e = nums.size() - 1;
        int ans = -1;

        while (s <= e) {
            int m = s + (e - s) / 2;

            if (nums[m] <= x) {
                ans = m;      // possible floor
                s = m + 1;    // go right to find bigger floor
            } else {
                e = m - 1;
            }
        }

        return ans;
    }
};


class Solution {
  public:
    int findCeil(vector<int>& nums, int x) {
        int s = 0, e = nums.size() - 1;
        int ans = -1;

        while (s <= e) {
            int m = s + (e - s) / 2;

            if (nums[m] >= x) {
                ans = m;      // possible ceil
                e = m - 1;    // go left to find smaller ceil
            } else {
                s = m + 1;
            }
        }

        return ans;
    }
};
