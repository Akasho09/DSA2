/*
Avoid re-computing m before the loop (line 17 is unnecessary).

Use const reference in canEat to avoid copying.
*/

// ceil(a / b) == (a + b - 1) / b

#include <iostream>
using namespace std;

    bool canEat(const vector<int>& piles, int h , int m ) {
        for(int i=0;i<piles.size();i++){
            h-=((piles[i]+m-1)/m);
            if(h<0) return false ;
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int e = INT_MIN;
        for(int i=0;i<n;i++){
            if(piles[i]>e) e=piles[i];
        }

        int s = 1;
        int m = s+(e-s)/2;

        while(s<e){
           m = s+(e-s)/2;
           if(canEat(piles,h,m)) e=m;
           else s=m+1;
        }

        return s;
    }



int main (){


    
}
