#include <iostream>
using namespace std;

    vector<int> rowGen(int n){
        vector<int>v ;
        int num=1;
        int j = n ;
        for(int i=0;i<=n;i++){
            v.push_back(num);
            num*=j--;
            num/=i+1;
        }
        return v;
    }


    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans ;

        for(int i=0;i<=numRows;i++){
            ans.push_back(rowGen(i));
        }

        return ans;

    }

int main (){

vector<vector<int>> v = generate(5);

for(int i=0;i<v.size();i++){
for(int j=0;j<v[i].size();j++){
    cout <<v[i][j] << " ";
}
cout <<endl;
}
cout<<endl;
    
}