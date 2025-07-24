/*
Given two sorted arrays nums1 and nums2, return an array that contains the 
union of these two arrays. 
The elements in the union must be in ascending order.

The union of two arrays is an array where all values are distinct and are present 
in either the first array, the second array, or both.
*/

#include <iostream>

using namespace std;

      vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        vector<int> unionArray;

        int i=0, j=0;

        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<=nums2[j]){
            if(unionArray.empty() || unionArray.back()!=nums1[i]) {
            unionArray.push_back(nums1[i]);
            }
            i++;
            } else {
                if(unionArray.empty() || unionArray.back()!=nums2[j]) unionArray.push_back(nums2[j]);
                j++;
            } 
            
        }

        while(i<nums1.size()) {
            if(unionArray.empty() || unionArray.back()!=nums1[i]) {
            unionArray.push_back(nums1[i++]);
        }}
        while(j<nums2.size()) {
            if(unionArray.empty() || unionArray.back()!=nums2[j]) {
                unionArray.push_back(nums2[j++]);
            }}
    
        return unionArray ;
    }


int main () {

    vector<int> nums1 =  { 1, 2, 3, 4, 5 ,15} ;
    vector<int> nums2 =  { 1, 2, 9 } ;


vector<int> nums = {1,2,3,1,2,3,4,1,2,6,5,1,5,2,2};

    vector<int>v = unionArray(nums1, nums2);
for(int i=0;i<v.size();i++){
    cout <<v[i] << " ";
}
cout<<endl;

}