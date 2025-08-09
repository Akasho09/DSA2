#include <iostream>
using namespace std;

class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int k = 0; k < 9; k++) {
            if (board[row][k] == c) return false; // row check
            if (board[k][col] == c) return false; // col check
            // 3×3 grid check
            int subRow = 3 * (row / 3) + k / 3;
            int subCol = 3 * (col / 3) + k % 3;
            if (board[subRow][subCol] == c) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board, int row, int col) {
        if (row == 9) return true; // solved
        if (col == 9) return solve(board, row + 1, 0); // next row
        if (board[row][col] != '.') return solve(board, row, col + 1); // skip filled cells

        for (char c = '1'; c <= '9'; c++) {
            if (isValid(board, row, col, c)) {
                board[row][col] = c;
                if (solve(board, row, col + 1)) return true;
                board[row][col] = '.';
            }
        }
        return false; // backtrack
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};


int main (){

    
}