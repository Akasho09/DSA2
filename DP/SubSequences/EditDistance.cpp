#include <iostream>
using namespace std;

int main (){



}


    int minDistance(string word1, string word2) {
        int n = word1.size() ,  m = word2.size();

        vector<int>c(m+1,0);
        vector<int>p(m+1,0);
        for(int j=1;j<=m;j++) p[j]=j;

        for(int i=1;i<=n;i++){
            c[0] = i;
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]) c[j]=p[j-1];
                else {
                    c[j] = 1 + min(c[j-1] , min(p[j-1] , p[j]) );
                }
        }
        p=c;
    }

    return p[m];
    }


    

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size() ,  m = word2.size();

        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                } else {
                    dp[i][j]=max(dp[i-1][j] , dp[i][j-1]);
                }
             }
        }

        cout << dp[n][m] <<" " ;

        int ans = 0 ;
        int i = n , j = m ;
        while( i>0 && j>0 ){
                if(word1[i-1]==word2[j-1]){
                    i--;j--;
                    if(i==0) return ans ;
                } else {
                    ans++;
                if(dp[i-1][j-1]==dp[i][j]) { 
                    i--; j--;

                } 
                else if(dp[i][j-1]==dp[i][j]) j--;
                else i--;
                }
        }
        cout << i <<" " <<j <<" " ;
        ans+=i+j;

       return ans ;
    }
};