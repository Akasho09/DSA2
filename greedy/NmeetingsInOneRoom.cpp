// Activity Selection Problem
#include <iostream>
using namespace std;



int main (){




}

    int maxMeetings(vector<int>& start, vector<int>& end) {
        vector<vector<int>>v;
        int n = start.size();
        for(int i=0;i<n;i++){
            vector<int>t;
            t.push_back(start[i]);
            t.push_back(end[i]);
             v.push_back(t);
        }
        
        sort(v.begin() , v.end() , [](const auto &a , const auto & b){
            return a[1]<b[1];
        });
        
        int ans = 0 ;
        int lastEnd = -1; 
        for(int i=0;i<n;i++){
            if(v[i][0]>lastEnd){ 
                ans++;
                lastEnd=v[i][1];
            }
        }
        
        return ans ;

    }
