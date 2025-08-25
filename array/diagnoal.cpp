#include <iostream>
using namespace std;

int main (){




}



vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    if (mat.empty() || mat[0].empty()) return {};

    int m = mat.size(), n = mat[0].size();
    vector<int> result;

    int row = 0, col = 0, direction = 1; 

    for (int i = 0; i < m * n; i++) {
        result.push_back(mat[row][col]);

        if (direction == 1) { 
            if (col == n - 1) {
                row++;
                direction = -1;
            } else if (row == 0) {
                col++;
                direction = -1;
            } else {
                row--;
                col++;
            }
        } else { 
            if (row == m - 1) {  
                col++;
                direction = 1;
            } else if (col == 0) { 
                row++;
                direction = 1;
            } else {
                row++;
                col--;
            }
        }
    }

    return result;
}