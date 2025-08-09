
#include <iostream>
using namespace std;

class Solution {
public:
    void helper(int n , vector<vector<string>>&ans ,vector<string>v , int ind){
        if(ind==n){
            for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            if(v[i][j]=='-')v[i][j]='.';
            }
            }
            ans.push_back(v); return ;
        }
       for(int i=0;i<n;i++){
        if(v[i][ind]=='-'){ 
            vector<string>temp = v;
            v[i][ind]='Q';
            int t1 = ind ;
            int t2 = i ;
            while(ind<n-1 && i>0 ) v[--i][++ind]='.';
            i=t2 ; ind = t1 ;
            while(ind<n-1) v[i][++ind]='.';
            i=t2 ; ind = t1 ;
            while(i<n-1 && ind<n-1 ) v[++i][++ind]='.';
            i=t2 ; ind = t1 ;
            helper(n , ans , v , ind+1);
            v=temp;
        }
       }
    }
    
    vector<vector<string> > solveNQueens(int n) {
       vector<vector<string>> ans;
       vector<string> v(n, string(n, '-'));
       helper(n , ans , v , 0); 
       return ans ;
    }

};


 
    bool isSafe(int row, int col, vector<string>& board, int n) {
        // Check column
        for (int i = 0; i < row; i++)
            if (board[i][col] == 'Q')
                return false;

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q')
                return false;

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q')
                return false;

        return true;
    }

    void helper(int row, int n, vector<vector<string>>& ans, vector<string>& board){
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                helper(row + 1, n, ans, board);
                board[row][col] = '.'; // backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        helper(0, n, ans, board);
        return ans;
    }


int main (){

vector<vector<string>> v2 = solveNQueens(4);
    for(int i=0;i<v2.size();i++){
    for(int j=0;j<v2[0].size();j++){
    cout <<v2[i][j] << " ";
    }
    cout <<endl;
}


// vector<string>v={ "akash" , "malik" };

// cout << v[0] <<endl;
// v[0][1]='2';
// cout << v[0][1] <<endl;


}