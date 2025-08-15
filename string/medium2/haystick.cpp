#include <iostream>
using namespace std;


int main (){




}


    int strStr(string haystack, string needle) {
        int m = haystack.size();  int n  = needle.size(); 
        for(int i=0;i<=m-n;i++){
            int s=0;
            int e=n-1;
        while(s<=e){
            if(haystack[s+i]==needle[s] && haystack[e+i]==needle[e]) {
                s++; e--;
            } else break;
        }
        if(s>e) return i;
        }
        return -1;
    }

    int strStr(string haystack, string needle) {

        return haystack.find(needle);
    }