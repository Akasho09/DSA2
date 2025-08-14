/*
1. Brute :
- find intersevtions of departures of with i+1 to n .
- max ibtersections is the answer.

*/

#include <iostream>
using namespace std;


int main (){




}



    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int ans = 0 , c = 0;
        int l=0 , r = 0 ;
        while(l<arr.size()){
            if(arr[l]<=dep[r]) { c++; l++; }
            else { r++; c--; }
            ans = max(ans, c);
        }
        
        return ans ;
    }