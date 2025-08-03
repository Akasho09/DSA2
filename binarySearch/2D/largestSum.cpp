class Solution {
public:

    bool possAns (vector<int>& nums, int k , int m){
        int sum=0;
        int count = 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > m) return false;
            if(sum+nums[i]>m){
                count++; sum=nums[i];
            } else {
                sum+=nums[i];
            }
        }
        if(count<=k) return true;
        return false;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int s = INT_MAX;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]<s) s=nums[i];
        }
        int e = 0;
        for(int i=0;i<nums.size();i++) e+=nums[i];

        int ans = e; 
        while(s<e){
            int m = s+(e-s)/2;
            if(possAns(nums , k  , m)){
                ans = m ; e = m ;
            } else s=m+1;
        }
        
        return ans ;
    }
};