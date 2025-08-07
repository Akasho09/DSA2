

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


        void mergeee(vector<int>& v , int s , int m , int e){
        int i = s;
        int j = m+1;
        vector<int>t;

        while(i<=m && j<=e){
            if(v[i]>v[j]) t.push_back(v[i++]);
            else t.push_back(v[j++]);
        }

        while(i<=m) t.push_back(v[i++]);
        while(j<=e) t.push_back(v[j++]);

        for (int k = 0; k < t.size(); ++k) v[s + k] = t[k];

    }

    void mergeSortt(vector<int>& v , int s , int e){
        if(s>=e) return ; 
        int mid = s+(e-s)/2;
        mergeSortt(v , s , mid);
        mergeSortt(v , mid+1 , e);
        mergeee(v, s , mid , e);
    }

int main (){

vector<int> nums = {1,2,3,5,4};

mergeSortt(nums , 0 , 5);
for(int i=0;i<nums.size();i++){
    cout <<nums[i] << " ";
}
cout<<endl;

    
}