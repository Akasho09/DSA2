#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        for(int i=0;i<n;i++){

            int s = 0;
            int e = m;

            while(s<=e){
                int mid = s+(e-s)/2;
                int left = (mid==0) ? -1 : mat[i][mid-1];
                int right = (mid==m-1) ? -1 : mat[i][mid+1];
                int top = (i==0) ? -1 : mat[i-1][mid];
                int bottom = (i==n-1) ? -1 : mat[i+1][mid];
                cout << mat[i][mid] <<endl;
                if((mat[i][mid]>left && mat[i][mid]>right) && (mat[i][mid]>top && mat[i][mid]>bottom)){
                    return {i,mid};
                }
                if(mat[i][mid]>right) e=mid-1;
                else s=mid+1;
            }
        }
                    return {-1,-1};
    }
};


class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int s = 0;
        int e = m-1;

        while(s<=e){
            int mid = s+(e-s)/2;

            int maxInCurrCol = 0 ;
            for(int i=0;i<n;i++){
                if(mat[i][mid]>mat[maxInCurrCol][mid]) maxInCurrCol=i;
            }

            int currEl=mat[maxInCurrCol][mid];
            int left = (mid==0) ? -1 : mat[maxInCurrCol][mid-1];
            int right = (mid==n-1) ? -1 : mat[maxInCurrCol][mid+1];

            if(currEl>left && currEl>right) return {maxInCurrCol,mid};
            else if (currEl>left) s=mid+1;
            else e=mid-1;
        }
        return {-1,-1};
        
    }
};


int main (){


    
}
