

#include <iostream>
using namespace std;

    void merge (vector<int>&nums , int l , int m , int r ){
        vector<int> left ;
        vector<int> right ;
        
        for(int i=l;i<=m;i++) left.push_back(nums[i]);
        for(int i=m+1;i<=r;i++) right.push_back(nums[i]);

        int i=0,j=0 ,k=l;

        while(i<left.size() && j<right.size()){
            if(left[i]<right[j]) nums[k++]=left[i++];
            else nums[k++]=right[j++];
        }

        while(i<left.size()) nums[k++]=left[i++];
        while(j<right.size()) nums[k++]=right[j++];

    }

    void mergeSortF2 (vector<int>& nums , int l , int r ){
         if(l>=r) return ;
         int mid = l+(r-l)/2;
          mergeSortF2(nums , l , mid );
          mergeSortF2(nums , mid +1 , r );
         merge (nums , l , mid , r);
    }


    vector<int> mergeSort(vector<int>& nums) {
         mergeSortF2(nums , 0 , nums.size()-1 );
         return nums ;
    }

int main (){

vector<int> nums = {1,2,3,5,4};

vector<int>v = mergeSort(nums);
for(int i=0;i<v.size();i++){
    cout <<v[i] << " ";
}
cout<<endl;

    
}