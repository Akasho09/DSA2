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
        k = k%s;
        for(int i=0;i<s/2;i++) {
            int temp2 = nums[(j+k)%s];
            nums[(j+k)%s]=temp;
            j+=k;
            temp = temp2;
        }

        temp = nums[1];
        j = 0;
        for(int i=1;i<s/2;i++) {
            int temp2 = nums[(j+k)%s];
            nums[(j+k)%s]=temp;
            j+=k;
            temp = temp2;
        }
    }

    void rotate4(vector<int>& nums, int k) {

        int s = nums.size();
        k = k%s;

        int j=0;
        while(j<s){
        for(int i=0;i<k;i++){
        if(j<s) swap(nums[j],nums[s-k+i]);
        j++;
        }
        
        }
    }


    void rotate5(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;  // In case k > n

    // Step 1: Reverse the entire array
    reverse(nums.begin(), nums.end());
    
    // Step 2: Reverse the first k elements
    reverse(nums.begin(), nums.begin() + k);
    
    // Step 3: Reverse the remaining n-k elements
    reverse(nums.begin() + k, nums.end());
}



void leftRotateByOne(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return;

    int first = nums[0];
    for (int i = 1; i < n; i++) {
        nums[i - 1] = nums[i];
    }
    nums[n - 1] = first;
}

int main (){

vector<int> nums = {1,2,3,4};

   rotate(nums , 2);

for(int i=0;i<nums.size();i++){
    cout <<nums[i] << " ";
}

cout<<endl;

vector<int> nums2 = {1,2,3,4,5,6,7};
    
rotate4(nums2 , 2);

for(int i=0;i<nums2.size();i++){
    cout <<nums2[i] << " ";
}

cout<<endl;

}