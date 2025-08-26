#include <iostream>
using namespace std;

int main (){




}

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m =grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i!=0 || j!=0){
                int top = (i>0) ? grid[i-1][j] : INT_MAX;
                int left = (j>0) ? grid[i][j-1] : INT_MAX;
                grid[i][j]+=(min(top,left));
                }
            }
        }

        return grid[n-1][m-1];
    }