
#include <iostream>
using namespace std;


    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size() , n=text2.size();
        vector<int>preRow(m+1,0);
        vector<int>currRow(m+1,0);
        for(int i=1;i<=n;i++){
            string curr = "";
            for(int j=1;j<=m;j++){
                if(text1[j-1]==text2[i-1]){ currRow[j]=preRow[j-1]+1 ;}
                else currRow[j]=max(preRow[j],currRow[j-1]);
            }
            preRow=currRow;
        }
        return currRow[m];
    }

int main (){

    longestCommonSubsequence("abdefcdefdeabc" , "aadefbdefccabce");


}