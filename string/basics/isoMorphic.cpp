
#include <iostream>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        int mapS[128] = {0};  // mapping from s to t
        int mapT[128] = {0};  // mapping from t to s

        for (int i = 0; i < s.size(); ++i) {
            if (mapS[s[i]] == 0 && mapT[t[i]] == 0) {
                mapS[s[i]] = t[i];
                mapT[t[i]] = s[i];
            } else {
                if (mapS[s[i]] != t[i] || mapT[t[i]] != s[i]) {
                    return false;
                }
            }
        }

        return true;
    }
};




int main (){


    
}