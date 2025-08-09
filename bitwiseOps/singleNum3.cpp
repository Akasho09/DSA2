class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n==2) return nums;
        int a ,b ;
        int i;
        for(i=1;i<n;i+=2){
            if(nums[i]!=nums[i-1]){
                a=nums[i-1]; break;
            }
        }
        i++;
        for(;i<n;i+=2){
            if(nums[i]!=nums[i-1]){
                b=nums[i-1]; 
                return {a,b};
            }
        }
        if(!b) b=nums[n-1];
        return {a,b};
    }
};