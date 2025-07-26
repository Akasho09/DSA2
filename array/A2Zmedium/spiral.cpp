
#include <iostream>
using namespace std;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
         int n = matrix.size();
         int m = matrix[0].size();
         vector<int> ans; 

         int i=0;
         int j=0;
         int r = n;
         int c = m ;

         while(r>=0 && c>=0){

            for(;j<c;j++){
                if(i<n && j<m) ans.push_back(matrix[i][j]); 
            }
            j--; i++ ; 

            for(;i<r;i++){
                if(i<n && j<m) ans.push_back(matrix[i][j]); 
            }
            i--;j--;

            for(;j>=m-c;j--){
                if(i<n && j<m) ans.push_back(matrix[i][j]); 
            }
            j++; i-- ; 

            for(;i>=n-r;i--){
                if(i<n && j<m)  ans.push_back(matrix[i][j]); 
            }
            i++; 
            j++; i++;
            
            cout << i <<" " <<j <<endl;
            c--; r--; 
         }


         return ans;

    }

    vector<int> spiralOrder2(vector<vector<int>>& matrix) {
         int n = matrix.size();
         int m = matrix[0].size();
         vector<int> ans; 

         int left =0 ;
         int top =0 ;
         int bottom = n-1;
         int right = m-1;

         while(left<=right && top<=bottom){

            for(int i=left ; i<=right ;i++ ){
                ans.push_back(matrix[top][i]); 
            }
            top++;

            for(int i=top ; i<=bottom ;i++){
                ans.push_back(matrix[i][right]); 
            }
            right--;

            if(top<=bottom){
            for(int i=right ; i>=left ; i--){
                ans.push_back(matrix[bottom][i]); 
            }
            bottom--;
            }

            if(left<=right){
            for(int i=bottom ; i>=top ; i--){
                ans.push_back(matrix[i][left]); 
            }
            left++;
            }

         }

         return ans;

    }





int main (){


    
}