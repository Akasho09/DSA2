#include <iostream>
using namespace std;



int main (){




}

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(),boxTypes.end(), [](const auto &a, const auto &b){
            return a[1]>b[1];
        });
        
        int ans = 0;
        int i=0;
        while(i<boxTypes.size() && truckSize>0){
            int m = (truckSize>=boxTypes[i][0]) ? boxTypes[i][0] : truckSize;
            ans+=(m*boxTypes[i][1]); 
            truckSize-=m; i++;
        }

        return ans ;
    }