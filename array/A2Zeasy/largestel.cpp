#include <iostream>
using namespace std;


    int largestElement(vector<int>& nums) {

    }

 
    int secondLargestElement(vector<int>& nums) {
      
        int maxi = INT_MIN;
        int sMaxi = INT_MIN;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi){
                if(maxi>sMaxi) sMaxi=maxi;
                maxi = nums[i];
            } else if (nums[i]>sMaxi) sMaxi = nums[i];
        }

        return sMaxi;
    }

int main (){

vector<int> nums = {1,2,3, 8, 6 ,5 ,7 , 9};

  cout<< secondLargestElement(nums); 
    cout<<endl;


    
}