#include <iostream>
using namespace std;

int romanToInt(string s) {
        unordered_map<char, int> roman = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
        };

        int ans = 0;
        int prevVal=0;

        for(int i=s.size()-1;i>=0;i--){
            int val = roman[s[i]];
            if(val<prevVal) ans-=val;
            else ans+=val;
            prevVal=val;
        }

        return ans ;
    }

int main (){

    
}