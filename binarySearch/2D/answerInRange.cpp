#include <iostream>
#include <numeric>
using namespace std;


    bool possAns(const vector<int>& bloomDay, int m, int k , int mid ) {
        int n = bloomDay.size();
        for(int i=0;i<n;i++){
            int j=0;
            for(; j<k && i<n ;j++){
                if(i<n && bloomDay[i++]>mid) { break;}
            }
            i--;
            if(j==k) m--;
            if(m==0) return true;
        }
        if(m<=0) return true;
        else return false ;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int s = 1;
        int e = INT_MIN;
        for(int i=0;i<n;i++){
            if(bloomDay[i]>e) e=bloomDay[i];
        }

        int  ans = -1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(possAns(bloomDay, m , k , mid)){ 
                ans = mid;
                e=mid-1;
            }
            else s=mid+1;
        }

        return ans ;
    }


  
    bool possAns(vector<int>& weights, int days, int capacity) {
        int currentLoad = 0;
        int requiredDays = 1;

        for (int weight : weights) {
            if (weight > capacity) return false;  // can't ship this package

            if (currentLoad + weight > capacity) {
                requiredDays++;
                currentLoad = 0;
            }
            currentLoad += weight;
        }

        return requiredDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int s = *max_element(weights.begin(), weights.end()); // minimum capacity = max weight
        int e = accumulate(weights.begin(), weights.end(), 0); // max capacity = total weight

        while (s < e) {
            int m = s + (e - s) / 2;
            if (possAns(weights, days, m)) {
                e = m; // try a smaller capacity
            } else {
                s = m + 1; // need more capacity
            }
        }

        return s; // or return e, since s == e
    }


int main (){


    
}
