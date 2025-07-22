#include <iostream>
using namespace std;

    int removeDuplicates(vector<int>& nums) {
        int ans = 1 ;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>=nums[i-1]){
                nums[ans++]=nums[i];
            }
        }

    }

int main (){


    vector<int> nums = {1,2,3,1,5,6,7,3,2};
removeDuplicates(nums);

for(int i=0;i<nums.size();i++){
    cout <<nums[i] << " ";
}
cout<<endl;

    
}