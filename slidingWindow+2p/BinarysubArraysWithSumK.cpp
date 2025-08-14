#include <iostream>
using namespace std;



int main (){

    
}


    int lessThanNequalTo(vector<int>& nums, int goal){
        int right = 0;
        int left=0 ; 
        int sum = 0;
        int ans = 0;

        while(right<nums.size()){
        if(goal<0) return 0;
            sum+=nums[right];
        while(sum>goal) {
                sum-=nums[left]; left++;
        }
        ans+=(right-left+1);
        right++;
        }
        return ans ;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return lessThanNequalTo(nums , goal )- lessThanNequalTo(nums , goal-1);
    }




    int numSubarraysWithSum(vector<int>& nums, int goal) {
      int ans = 0;
      unordered_map<int , int> mapp ;
      mapp[0]=1;
      
      int sum = 0;
      for(int i=0;i<nums.size();i++){
        if(nums[i]==1) sum++;
        if(mapp.find(sum-goal)!=mapp.end()) ans+=mapp[sum-goal];
        mapp[sum]++;
      }

       return ans ;
    }
