#include <iostream>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums, int left, int mid, int right , vector<int>& orginalIndexes) {
    vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (nums[i] >= nums[j]){
            temp.push_back(nums[i++]);
            orginalIndexes.push_back(i);
        }
        else { 
            temp.push_back(nums[j++]);
            orginalIndexes.push_back(j);
        }
    }

            
    while (i <= mid) {
    temp.push_back(nums[i++]);
    orginalIndexes.push_back(i);
}
    while (j <= right) {
    temp.push_back(nums[j++]);
    orginalIndexes.push_back(j);
}

    for (int k = 0; k < temp.size(); ++k) {
        nums[left + k] = temp[k];
    }
}

vector<int> mergeSort(vector<int>& nums, int left, int right) {
    
    vector<int>orginalIndexes ;
    if (left >= right) return orginalIndexes;

    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid );
    mergeSort(nums, mid + 1, right);
    merge(nums, left, mid, right , orginalIndexes);

    return orginalIndexes;
}


int main (){
// string s1 = "azadb";
// string s2 = "azadaz";
// cout << (s1>=s2) ;

vector<int>v = {1,2,5,9,3,4};
sort(v.begin(), v .end());
int n = v.size();
int mid = v[(n+1)/2];
for(int i=0;i<n;i++) {
    v[i]-=mid;
    if(v[i]<0) v[i]=-v[i];
    cout <<v[i] <<" ";
}
cout <<endl;
 vector<int>orginalIndexes  = mergeSort(v,0,6);
for(int i=0;i<v.size();i++) {
    cout <<v[i] <<"\t";
    cout <<orginalIndexes[i] <<endl;
}
cout <<endl;
    
}