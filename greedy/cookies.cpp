#include <iostream>
using namespace std;



int main (){




}

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end()); // sort greed factors
    sort(s.begin(), s.end()); // sort cookie sizes
    int child = 0, cookie = 0;
    
    while (child < g.size() && cookie < s.size()) {
        if (s[cookie] >= g[child]) {
            // child is satisfied
            child++;
        }
        cookie++; // move to next cookie
    }
    
    return child; // number of content children
}
