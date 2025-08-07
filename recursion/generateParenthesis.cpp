#include <iostream>
using namespace std;

    void helper(int n , int open , int close , string current , vector<string>&ans){
    if (open == n && close == n) {
        ans.push_back(current);
        return;
    }

        if(open<n) helper(n, open+1 , close , current+'(' , ans);
        if(open>close) helper(n, open , close+1 , current+')' , ans);
    }
    vector<string> generateParenthesis(int n ) {
        vector<string>ans ;

        helper(n, 0 , 0 , "" , ans);

        return ans ;
    }


int main (){

    
}