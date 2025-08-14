#include <iostream>
using namespace std;



int main (){




}

    bool checkValidString(string s) {
        int n = s.size();
        int minn = 0;
        int maxx = 0;
        for(int i =0 ; i<n ;i++){
            if(s[i]=='(') { minn++; maxx++; }
            else if (s[i]==')') { minn--; maxx--; }
            else { minn--; maxx++; }

            if(maxx<0) return false;
            if(minn<0) minn=0;
        }

        return minn==0;
    }