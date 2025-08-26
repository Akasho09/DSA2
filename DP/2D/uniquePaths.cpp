#include <iostream>
using namespace std;

int main (){




}

    vector<vector<int>> dp; 

    int helper(int m, int n) {
        if (m <= 1 || n <= 1) return 1;
        if (dp[m][n] != -1) return dp[m][n];

        dp[m][n] = helper(m-1, n) + helper(m, n-1);
        return dp[m][n];
    }

    int uniquePaths(int m, int n) {
        dp.assign(m+1, vector<int>(n+1, -1));
        return helper(m, n);
    }