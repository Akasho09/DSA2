#include <iostream>
using namespace std;


int main (){




}


vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> result;
    int i = 0, n = intervals.size();
    int start = newInterval[0], end = newInterval[1];

    // 1️⃣ Add all intervals before newInterval
    while (i < n && intervals[i][1] < start) {
        result.push_back(intervals[i]);
        i++;
    }

    // 2️⃣ Merge overlaps
    while (i < n && intervals[i][0] <= end) {
        start = min(start, intervals[i][0]);
        end = max(end, intervals[i][1]);
        i++;
    }
    result.push_back({start, end});

    // 3️⃣ Add remaining intervals
    while (i < n) {
        result.push_back(intervals[i]);
        i++;
    }

    return result;
}