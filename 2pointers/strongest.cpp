#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:

void merge(vector<int>& nums, int left, int mid, int right , vector<int>& orginalIndexes) {
    vector<int> tempNums;
    vector<int> tempIndexes;

    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (nums[i] >= nums[j]) {
            tempNums.push_back(nums[i]);
            tempIndexes.push_back(orginalIndexes[i]);
            i++;
        } else {
            tempNums.push_back(nums[j]);
            tempIndexes.push_back(orginalIndexes[j]);
            j++;
        }
    }

    while (i <= mid) {
        tempNums.push_back(nums[i]);
        tempIndexes.push_back(orginalIndexes[i]);
        i++;
    }

    while (j <= right) {
        tempNums.push_back(nums[j]);
        tempIndexes.push_back(orginalIndexes[j]);
        j++;
    }

    for (int k = 0; k < tempNums.size(); ++k) {
        nums[left + k] = tempNums[k];
        orginalIndexes[left + k] = tempIndexes[k];
    }

    // // Debug output
    // for (int i = 0; i < orginalIndexes.size(); i++) {
    //     cout << orginalIndexes[i] << " ";
    // }
    // cout << endl;
}


vector<int> mergeSort(vector<int>& nums, int left, int right,  vector<int>& orginalIndexes) {
    
    if (left >= right) {
        return orginalIndexes;
    }

    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid , orginalIndexes);
    mergeSort(nums, mid + 1, right , orginalIndexes);
    merge(nums, left, mid, right , orginalIndexes);

    return orginalIndexes;
    }

vector<int> getStrongest(vector<int>& v, int k) {

sort(v.begin(), v.end(), [](int a, int b) {
    return a > b;  // descending
    });

vector<int> v2=v;

int n = v.size();
if(k==n) return v;

int index = n/2;
int mid = v[index];
cout <<mid <<endl;
for(int i=0;i<v.size();i++) {
    v[i]-=mid;
    if(v[i]<0) v[i]=-v[i];
    }


vector<int> orginalIndexes(n);
iota(orginalIndexes.begin(), orginalIndexes.end(), 0);

mergeSort(v, 0 , v.size()-1 , orginalIndexes );

 vector<int> ans ;
 for(int i=0;i<k;i++){
    ans.push_back(v2[orginalIndexes[i]]);
    }

 return ans ;
 }
 };


 class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());  // Sort ascending to find median
        int n = arr.size();
        int median = arr[(n - 1) / 2];

        sort(arr.begin(), arr.end(), [median](int a, int b) {
            int da = abs(a - median), db = abs(b - median);
            if (da == db) return a > b; // If equal distance, pick larger
            return da > db;             // Otherwise, pick one with greater distance
        });

        return vector<int>(arr.begin(), arr.begin() + k);
    }
};

