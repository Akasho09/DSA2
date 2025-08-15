#include <iostream>
using namespace std;


int main (){

vector<vector<int>>v={{1,2},  {2,9} , {2,6} , {3,4} , {2,3} , {2,4}};

sort(v.begin(),v.end() , []( vector<int> &a , vector<int>& b){
    return a[0]<=b[0];
});

    for(int i=0;i<v.size();i++){
    for(int j=0;j<v[0].size();j++){
    cout <<v[i][j] << " ";
    }
    cout <<endl;
}
}


