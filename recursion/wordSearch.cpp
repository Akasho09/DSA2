#include <iostream>
using namespace std;

class Solution {
public:
    bool helper(vector<vector<char>>& board, string word , string curr , int i , int j , int ind){        
        if(ind==word.size()) return true ;

        if(i<0 || j<0 || i==board.size() || j==board[0].size() || board[i][j]!=word[ind]){
            return false ;
        }
        char temp = board[i][j];
        board[i][j] = '#';

        bool found =  helper(board , word , curr , i+1 , j , ind) || 
        helper(board , word , curr , i-1 , j , ind) || 
        helper(board , word , curr , i , j+1 , ind) || 
        helper(board , word , curr , i , j-1 , ind);

        board[i][j] = temp ;

        return found ;
    }

    bool exist(vector<vector<char>>& board, string word) {

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(helper(board , word , "" , 0 , 0 , 0 )){
                    reur true ;
                }
            }
        }
        return false ;
        
    }
};


int main (){

    
}