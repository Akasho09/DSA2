/*
Given an integer array nums, rotate the array to the right by k steps, 
where k is non-negative.

*/

#include <iostream>
using namespace std;

    void rotate(vector<int>& nums, int k) {
        vector<int> ans ;

        for(int i = nums.size()-k;i<nums.size();i++){
            ans.push_back(nums[i]);
        }        
        for(int i = 0 ;i<nums.size()-k;i++){
            ans.push_back(nums[i]);
        }
        nums=ans;
    }


    void rotate2(vector<int>& nums, int k) {
        vector<int> ans ;

        for(int i=0 ; i<nums.size();i++) {
            ans.push_back(nums[(nums.size()-k+i)%nums.size()]);
        }
        nums=ans;

    }



    void rotate3(vector<int>& nums, int k) {
        int j = 0;
        int temp = nums[0];
        int s = nums.size();
        for(int i=0;i<s;i++) {
            int temp2 = nums[(j+k)%s];
            nums[(j+k)%s]=temp;
            j+=k;
            temp = temp2;
        }
    }
int main (){

vector<int> nums = {1,2,3,9};

   rotate(nums , 2);

for(int i=0;i<nums.size();i++){
    cout <<nums[i] << " ";
}

cout<<endl;

vector<int> nums2 = {1,2,3,9};
    
rotate3(nums2 , 2);

for(int i=0;i<nums2.size();i++){
    cout <<nums2[i] << " ";
}

cout<<endl;

}