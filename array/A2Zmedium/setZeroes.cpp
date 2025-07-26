#include <iostream>
using namespace std;

    void setZeroes(vector<vector<int>>& matrix) {
        int row[matrix.size()];
        int col[matrix[0].size()];

        for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j]==0){
                row[i]=0;
                col[j]=0;
            }
        }
        }

        for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(row[i]==0 || col[j]==0 ){ matrix[i][j]=0; }
        }
        }
    }


void setZeroes2(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    bool firstRow = false, firstCol = false;

    for (int j = 0; j < n; j++) {
        if (matrix[0][j] == 0) firstRow = true;
    }

    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) firstCol = true;
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if (firstRow) {
        for (int j = 0; j < n; j++) {
            matrix[0][j] = 0;
        }
    }

    if (firstCol) {
        for (int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }
}

int main (){


    vector<vector<int>> v2 = {
         { 0,1,2,0 } , { 3,4,5,2 } ,{ 1,3,1,5 } 
    };
    setZeroes2(v2);
    for(int i=0;i<v2.size();i++){
    for(int j=0;j<v2[0].size();j++){
    cout <<v2[i][j] << " ";
    }
    cout <<endl;

}
    
}