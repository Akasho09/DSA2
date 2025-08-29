#include <iostream>
using namespace std;


    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size() , n=text2.size();
        vector<vector<int>>dp(n+1 , vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=i;j<=m;j++){
                int top=dp[i-1][j];
                int left=dp[i][j-1];
                if(text1[j-1]==text2[i-1]) top++;
                dp[i][j]=max(top,left);
                cout <<text2[i-1] <<" " <<text1[j-1] <<" "  <<dp[i][j] <<endl;
            }
            cout <<dp[i][m] <<" \n" ;
        }

        return dp[n][m];
    }

int main (){

    longestCommonSubsequence("abdefcdefdeabc" , "aadefbdefccabce");


}
