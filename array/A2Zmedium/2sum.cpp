
#include <iostream>
using namespace std;



vector<int> twoSum(vector<int>& nums, int target) {
int i=0;
        while (i<nums.size()){
int j=i+1;
    while (j<nums.size()){
if (nums[j]==target-nums[i]){
return {i,j};
}
j++;
}
 i++;
}
 return {};
}

vector<int> twoSum2(vector<int>& nums, int target) {
    int sum = 0;
    vector<int> ans ;
    unordered_map<int , int>preMap ;

    for(int i =0; i<nums.size();i++){
        sum+=nums[i];

        if(preMap.find(sum-target)!=preMap.end()){
            return {preMap[sum-target] , i };
        }

        preMap[sum]= i ;

    }

}


int main (){


    
}