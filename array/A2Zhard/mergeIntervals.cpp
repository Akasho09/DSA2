/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
and return an array of the non-overlapping intervals that cover all the intervals in the input.

*/

#include <iostream>
using namespace std;

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        if (intervals.empty()) return ans;
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        int j = 0 ;
        // same array
        for (int i = 1; i < intervals.size(); i++) 
            if (intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);
            } else {
                intervals[j][0]=start;
                intervals[j++][1]=end;
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
                intervals[j][0]=start;
                intervals[j][1]=end;

                return vector<vector<int>>(intervals.begin(), intervals.begin() + j);
    }

        vector<vector<int>> merge2(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        int i =0;
        int n = intervals.size();
        int newI=i;
        int l =intervals[i][0];
        int r = intervals[i][1];
        while(i<n){
            if(newI<n-1 && (r>=intervals[newI+1][0] && intervals[newI+1][1]>=l)) {
                newI++;
                r=max(r,intervals[newI][1]);
                l=min(l,intervals[newI][0]);
            }
            else {
                ans.push_back({l,r});
                newI++; i=newI;
                if(i<n) l = intervals[i][0];
                if(i<n) r = intervals[i][1];
            }
        }

        return ans ;
    }

int main (){


    
}
