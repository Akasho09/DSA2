#include <iostream>
using namespace std;

int main (){
    


}


class Solution {
public:
    bool isAllStars(string &p, int i) {
        for (int j = i; j < p.size(); j++) {
            if (p[j] != '*')
                return false;
        }
        return true;
    }

    bool isMatch(string s, string p) {
        int n=s.size() , m =p.size();
        vector<vector<bool>>dp(n+1, vector<bool>(m+1, false ));
        dp[0][0]=true;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?') dp[i][j]= true;
                else if(p[j-1]=='*'){
                    dp[i][j]= dp[i-1][j] || dp[i][j-1];
                }
            }
        }

        return dp[n][m];
    }
};


class Solution {
public:
    bool isAllStars(string &p, int i) {
        for (int j = i; j < p.size(); j++) {
            if (p[j] != '*')
                return false;
        }
        return true;
    }
    bool helper(int i , int j , string s, string p , vector<vector<int>>&dp){
        if(i==s.size() && j==p.size()) return true;
        if(j==p.size()) return false;
        if(i==s.size()) return isAllStars( p , j );

        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j]=helper( i+1 , j+1 ,  s,  p , dp);
        }

        if(p[j]=='*'){
            return dp[i][j]=helper( i+1 , j ,  s,  p , dp) || helper( i , j+1 ,  s,  p , dp) ; 
        } else return false;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size() , vector<int>(p.size(),-1));
        return helper(0 , 0 ,s, p , dp);
    }
};