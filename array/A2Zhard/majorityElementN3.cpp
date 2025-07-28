/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
*/


#include <iostream>
using namespace std;


    vector<int> majorityElement(vector<int>& nums) {
        int ans = nums[0];
        int count = 1;
        int prev = 0;

        for(int i=0;i<nums.size();i++){
            
            if(count>0){
                if(nums[i]==ans) count++;
                else if(!prev) prev = nums[i];
                else { count--; prev = 0; }
            } else {
                ans = nums[i];
                count = 1;
                prev = 0 ;
            }
        }
        return {ans}; 
    }



    vector<int> majorityElement(vector<int>& nums) {
        int num1=INT_MIN, num2 =INT_MIN;
        int count1 = 0 , count2 = 0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(count1==0 && nums[i]!=num2) {
                num1=nums[i];
            }
            else if (count2==0 && nums[i]!=num1) {
                num2=nums[i];
            }
            else if (nums[i]==num1) count1++;
            else if (nums[i]==num2) count2++;
            else {
                count1--; count2--;
            }
        }

        count1=0; count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==num1) count1++;
            if(nums[i]==num2) count2++;
        }

        vector<int> ans;
        if(count1>=n/3) ans.push_back(num1);
        if(count2>=n/3) ans.push_back(num2);

        return ans ;

    }


int main (){


    
}