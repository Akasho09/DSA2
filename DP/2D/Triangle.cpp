#include <iostream>
using namespace std;

int main (){




}


    int minimumTotal(vector<vector<int>>& triangle) {

        for(int i=0;i<triangle.size();i++){
            for(int j=0;j<triangle[i].size();j++){
                if(i!=0 || j!=0){
                int left = (i>0 && j>0) ? triangle[i-1][j-1] : INT_MAX;
                int right = (i>0 && j<triangle[i-1].size()) ? triangle[i-1][j] : INT_MAX;
                triangle[i][j]+=(min(left,right));
                }
            }
        }

        int ans = INT_MAX;
        int n = triangle.size();
        int m = triangle[n-1].size();
        for(int i=0;i<m ;i++){
            if(ans>triangle[n-1][i]) ans = triangle[n-1][i] ;
        }

        return ans ;
    }