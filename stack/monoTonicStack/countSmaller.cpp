#include <iostream>
using namespace std;


int main (){




}


    int elsLesser(vector<int>&els , int curr){
        int s = 0 ;
        int e = els.size()-1;
        while(s<e){
            int m = s+(e-s)/2;
        if(els[m]>=curr){
            e=m;
        } else s=m+1;
        }
        
        return s+1;
    }
    vector<int> countSmaller2(vector<int>& nums) {
        int n = nums.size();
        vector<int>lessEls(n,0);
        vector<int>els;
        for(int i=n-1;i>=0;i--){
            if(els.size()==0){
                lessEls[i]=-1;
                els.push_back(nums[i]);
            } else {
                lessEls[i]=elsLesser(els,nums[i]);
                
            }

        }
        return lessEls;

    }