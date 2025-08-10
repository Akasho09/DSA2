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


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long x = 0;
        for(int i=0;i<nums.size();i++) x^=nums[i];

        x = x&(-x); 
        int a=0 , b=0 ;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&x) a^=nums[i];
            else b^=nums[i];
        }

        return {a,b};
    }
};