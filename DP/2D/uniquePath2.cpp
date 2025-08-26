#include <iostream>
using namespace std;

int main (){




}


class Solution {
public:
    int helper(int i , int j , vector<vector<int>>& obstacleGrid){
        if(obstacleGrid[i][j]!=-1) return obstacleGrid[i][j];
        if(i>=obstacleGrid.size()-1 || j>=obstacleGrid[0].size()-1){
            return 1;
        }
        return obstacleGrid[i][j] = helper(i,j+1,obstacleGrid) + helper(i+1, j , obstacleGrid);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if(obstacleGrid[n-1][m-1]==1) return 0 ; 

        for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            if(obstacleGrid[i][j]==1) obstacleGrid[i][j]=0;
            else obstacleGrid[i][j]=-1;
        }
        }
        for(int j=m-1;j>=0;j--){
            if(obstacleGrid[n-1][j]==1) {
               while(j>=0) obstacleGrid[n-1][j--]=0;
            } else obstacleGrid[n-1][j]=-1;
        }
        for(int j=n-1;j>=0;j--){
            if(obstacleGrid[j][m-1]==1) {
               while(j>=0) obstacleGrid[j--][m-1]=0;
            } else obstacleGrid[j][m-1]=-1;
        }

        return helper(0,0,obstacleGrid);
    }
};



class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n, 0));

        // Base case
        if (grid[0][0] == 1) return 0;
        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dp[i][j] = 0; // obstacle
                } else {
                    if (i > 0) dp[i][j] += dp[i-1][j];
                    if (j > 0) dp[i][j] += dp[i][j-1];
                }
            }
        }

        return dp[m-1][n-1];
    }
};
