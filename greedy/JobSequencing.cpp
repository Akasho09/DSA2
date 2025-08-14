#include <iostream>
using namespace std;


int main (){




}

class Solution {
public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<pair<int, int>> jobs;

        for (int i = 0; i < n; i++) {
            jobs.push_back({deadline[i], profit[i]});
        }

        // Sort jobs by profit in descending order
        sort(jobs.begin(), jobs.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        // Find the max deadline
        int maxDeadline = 0;
        for (auto &job : jobs) {
            maxDeadline = max(maxDeadline, job.first);
        }

        vector<int> slot(maxDeadline + 1, -1); // slot[i] = job index or -1
        int countJobs = 0, totalProfit = 0;

        for (int i = 0; i < n; i++) {
            for (int j = jobs[i].first; j > 0; j--) { // find latest free slot
                if (slot[j] == -1) {
                    slot[j] = i;
                    countJobs++;
                    totalProfit += jobs[i].second;
                    break;
                }
            }
        }

        return {countJobs, totalProfit};
    }
};


class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n = deadline.size();
        vector<pair<int , int >>v;
        for(int i=0;i<n;i++){
            pair<int , int >a;
            a.first=deadline[i];
            a.second=profit[i];
            v.push_back(a);
        }

        sort(v.begin() , v.end() , [](const auto & a, const auto & b){
            return a.second > b.second;
        });
        
        int timee = 0 ;
        int ans = 0 ;
        int c  = 0;
        for(int i=0;i<n;i++){
            if(v[i].first>=timee) {
                ans+=v[i].second; c++; timee++;
            }
        }
        
        return { c , ans } ;
    }
};