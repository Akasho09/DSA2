  // Shortest Job first
#include <iostream>
using namespace std;


int main (){




}



  long long solve(vector<int>& bt) {
        // code here
       sort(bt.begin(),bt.end());
       int n = bt.size();
       long long ans = 0 ;
       long long sum = 0 ;
       for(int i=0;i<n-1;i++){
           sum+=bt[i];
           ans+=sum;
       }

       return (ans)/n ;
    }