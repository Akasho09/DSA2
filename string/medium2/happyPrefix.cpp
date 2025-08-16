/*
A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).

Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.
*/
#include <iostream>
using namespace std;


int main (){




}



    string longestPrefix(string s) {
        int n = s.size();
        vector<int>lps(n,0);

        int ind = 0;
        for(int i=1;i<n;i++){
            if(s[i]==s[ind]){
                ind++;
                lps[i]=ind; 
            }else {
                if(ind!=0){
                    ind = lps[ind-1];
                    i--;
                }else {
                    ind=0; 
                }
            }
        }

        int maxInd = lps.back();

        return s.substr(n-maxInd);
    }