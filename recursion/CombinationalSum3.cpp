
#include <iostream>
using namespace std;

class Solution {
public:
    void helper(int k, int n , vector<vector<int>>&ans , vector<int>v , int s){

        if(n==0 || v.size()==k){
            if(n==0 && v.size()==k) ans.push_back(v); 
            return ;
        }

        for(int i=s+1;i<=9;i++){
        if (i > n) break;
        v.push_back(i); 
        helper(k,n-i,ans,v,i);
        v.pop_back();
        }

    }

    vector<vector<int>> combinationSum3(int k, int n) {
       vector<vector<int>>ans ;
       vector<int>v ;
       helper(k,n,ans,v,0);
       return ans ;
    }
};


int main (){

    
}