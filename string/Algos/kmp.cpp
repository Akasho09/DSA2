#include <iostream>
using namespace std;


    int strStr(string haystack, string needle) {
        int n = haystack.size() , m = needle.size();

        vector<int>lps(m,0);
        int ind = 0;
        for(int i=1; i<m;){
            // If characters match, increment the size of lps
            if(needle[i]==needle[ind]) {
                ind++;
                lps[i]=ind;  i++;
            } else {
                if(ind!=0){
                // Update len to the previous lps value
                // to avoid reduntant comparisons
                   ind = lps[ind-1];
                } else {
                    // If no matching prefix found, set lps[i] to 0
                    lps[i]=0;  i++;
                }
            }
        }

        for(int i=0;i<lps.size();i++) cout <<needle[i] <<" "  ;
        cout<<endl;
        for(int i=0;i<lps.size();i++) cout <<lps[i] <<" "  ;

        ind = 0;
        for(int i=0;i<n;i++){
            if(haystack[i]==needle[ind]){
                ind++;
            if(ind==m) return i-m+1;
            }else {
            // Use lps value of previous index
            // to avoid redundant comparisons
              if(ind!=0){
                ind = lps[ind-1]; i--;
              }
            }
        }

        return -1;    
    }

int main() {
    strStr("" , "ababab");

}
