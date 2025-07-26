#include <iostream>
using namespace std;


   void rotate(vector<vector<int>>& matrix) {
        
        int m = matrix[0].size();
        int n = matrix.size();
        // transpose 
        for(int i=0;i<n;i++){
        for(int j=i+1;j<m;j++){
            swap(matrix[i][j],matrix[j][i]);
        }}

        for(int i=0;i<n;i++){
            int l=0;
            int r=m-1;
            while(l<r){
            swap(matrix[i][l++],matrix[i][r--]);
            }
        }
        }



int main (){


    
}
