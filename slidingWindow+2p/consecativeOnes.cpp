
#include <iostream>
using namespace std;

    int findMaxConsecutiveOnes(vector<int>& nums) {
        int start = -1;
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                ans=max(ans,i-start-1);
                start=i;
            }
        }
        ans=max(ans,n-start-1);
        return ans ;
    }


    int findMaxConsecutiveOnes3(vector<int>& nums, int k) {
        int start = 0;
        int t = k ;
        int n = nums.size();
        int ans =  0 ;
        int firstZero ;

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(t==k) firstZero=i;
                t--;
                if(t<0) {
                    ans = max(ans,i-start);
                    i=firstZero+1;
                    start=i;
                    t=k;
                }
            }
        }
        ans = max(ans,n-start-1);
        return ans ;
    }



int main (){

    
}