#include <iostream>
#include <unordered_set>
using namespace std;



    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>count ;

        for(int i=0;i<nums.size();i++){
            if(count.find(nums[i])!=count.end()){
                count[nums[i]]++;
            } else if(count.find(nums[i]-1)!=count.end()) count[nums[i]-1]++;
            else if(count.find(nums[i]+1)!=count.end()) count[nums[i]+1]++;
        }

    }

    // usind set DS
    // COMPLEXITY = 0(N)
    // If the unordered_set suffers from hash collisions, worst-case complexity can degrade to O(n²). 
    // But in practice (and interviews), it's acceptable to say this is O(n).

    int longestConsecutive2(vector<int>& nums) {
        unordered_set<int>s ;

        for(int i=0;i<nums.size();i++) {
            s.insert(nums[i]);
        }

        int ans = 1;

        for(auto i : s){
            if(s.find(i-1)==s.end()){
                int c  = 1;
                int x = i;
                while(s.find(x+1)!=s.end()){
                    c++;x++;
                }
                ans= max(ans,c);
            }
        }
        return ans ;
    }


int main (){


    
}