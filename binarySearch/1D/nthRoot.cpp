
#include <iostream>
using namespace std;

    int nthRoot(int n, int m) {
        int s =  0 ;
        int e = m/n;
        int mid = s+(e-s)/2;
        
        while(s<=e){
            mid = s+(e-s)/2;
            int mult=1;
            int i;
            for(i=0;i<n;i++) {
                if(mult*mid<=m) mult*=mid;
                else break;
            }

            if(i==n && mult==m) return mid;
            else if(i==n) s=mid+1;
            else e=mid-1;
        }

        return -1;
    }




int main (){


    
}
