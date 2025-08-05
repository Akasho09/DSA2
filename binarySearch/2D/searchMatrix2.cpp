
#include <iostream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int c = matrix[0].size()-1;
        int r = 0;
        while(c>=0 && r<matrix.size()){
            if(matrix[r][c]==target) return true;
            else if (matrix[r][c]>target) c--;
            else r++;
        }
        return false;
    }
};



int main (){


    
}
