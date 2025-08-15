#include <iostream>
using namespace std;


int main (){




}


    int minAddToMakeValid(string s) {
        int n = s.size();
        int ans = 0;
        int c = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') c++;
            else c--;
            if(c<0){
                i++;
                while(i<n && s[i]==')') {
                c--; i++;
                }
                ans-=(c);
                c=0; i--;
            }
        }
        ans+=(c);
        return ans ;
    }