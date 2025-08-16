#include <iostream>
using namespace std;


int main (){




}


class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());

        // Build combined string
        string combined = s + "#" + rev;

        // Compute LPS
        vector<int> lps(combined.size(), 0);
        for (int i = 1; i < combined.size(); i++) {
            int len = lps[i-1];
            while (len > 0 && combined[i] != combined[len]) {
                len = lps[len-1];
            }
            if (combined[i] == combined[len]) {
                len++;
            }
            lps[i] = len;
        }

        // Length of longest palindromic prefix
        int longestPrefix = lps.back();

        // Add remaining part of rev in front of original s
        return rev.substr(0, n - longestPrefix) + s;
    }
};
