#include <iostream>
using namespace std;


int main (){




}

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       sort(intervals.begin(), intervals.end()); 
        int n = intervals.size();
        int ind = 0;

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] <= intervals[ind][1]) {
                intervals[ind][1] = max(intervals[ind][1], intervals[i][1]);
            } else {
                ind++;
                intervals[ind] = intervals[i];
            }
        }

        return vector<vector<int>>(intervals.begin(), intervals.begin() + ind + 1);
    }