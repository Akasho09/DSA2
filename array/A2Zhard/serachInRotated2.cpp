class Solution {
public:
bool search(vector<int>& nums, int target) {
    int n = nums.size();
      int s =0;
      int e = n-1;
      int m = s+(e-s)/2;
      while(s<=e){
        m = s+(e-s)/2;

        if(nums[m]==target) return true ;

        if(nums[s]==nums[m] && nums[m]==nums[e]){
            s++; e--;
        }
        else if (nums[m]>=nums[s]){
            if(target>=nums[s] && target<nums[m]) e=m-1; 
            else s=m+1; 
        } else {
            if(target<=nums[e] && target>nums[m]) s=m+1;
            else e=m-1;
        }
      }

      return 0;
    }
};