

#include <iostream>
using namespace std;

   vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>>ans ;
        unordered_map<int , vector<string> > mapp;
        for(int i=0;i<n;i++){
            int xoor=0;
            for(int j=0;j<strs[i].length();j++){
                xoor^=strs[i][j];
            }
            mapp[xoor].push_back(strs[i]);
        }

        vector<string>s ;
        for (const auto& [key, vec] : mapp) {
        vector<string>v;
        for (const auto& str : vec) {
        v.push_back(str);
        }
        ans.push_back(v);
        }

        return ans ;
    }



        vector<vector<string>> groupAnagrams2(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string , vector<string>> mapp;
        vector<vector<string>>ans ;
        
        for(int i=0;i<n;i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end()); 
            mapp[temp].push_back(strs[i]);
        }

        for( auto [i,vec] : mapp ){
           vector<string>v ;
        for( auto j : vec ){
            v.push_back(j);
        }
        ans.push_back(v);
        }

        return ans ;
    }


int main (){


    
}
