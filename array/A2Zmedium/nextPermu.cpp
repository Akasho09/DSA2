#include <iostream>
using namespace std;


    void nextPermutation(vector<int>& nums) {
        int p = nums.size()-1;
        while(nums[p]<nums[p-1] && p>=0){p--;};
        cout <<p <<endl;
        int s = p-1; p = nums.size()-1;
        while(nums[p]<=nums[s]){p--;};
        cout <<p <<endl;
        swap(nums[s],nums[p]);
        sort(nums.begin()+s+1,nums.end());
        }


        void nextPermutation2(vector<int>& nums) {
    int n = nums.size();
    int p = n - 1;

    // Step 1: Find the first index 's' such that nums[s] < nums[s + 1] from the end
    int s = n - 2;
    while (s >= 0 && nums[s] >= nums[s + 1]) s--;

    // Step 2: If such an index exists, find the smallest element > nums[s] to the right
    if (s >= 0) {
        p = n - 1;
        while (nums[p] <= nums[s]) p--;
        swap(nums[s], nums[p]);
    }

    // Step 3: Reverse the sequence from s+1 to the end
    reverse(nums.begin() + s + 1, nums.end());
}

int main (){

    vector<int> nums = {1,5,1};

    nextPermutation(nums);
for(int i=0;i<nums.size();i++){
    cout <<nums[i] << " ";
}
cout<<endl;

    
}

