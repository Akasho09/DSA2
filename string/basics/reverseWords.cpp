#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

    string reverseWords(string s) {
        string ans = "";
        string word = "";
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!=' ') { word+=s[i]; }
            else {
                if(word.size()>0) {
                    reverse(word.begin(), word.end());
                    if(ans.size()>0) ans+=' ';
                    ans+=word;
                    word="";
                }
            }
        }
        if(word.size()>0){
        reverse(word.begin(), word.end());
        if(ans.size()>0) ans+=' ';
        ans+=word;   
        }
        return ans ;
    }

    class Solution {
public:
    string reverseWords2(string s) {
        stringstream iss (s);
        vector<string>v ;
        string word ;

        while(iss >> word){
            v.push_back(word);
        }

        reverse(v.begin(),v.end());

        ostringstream ans ;
        for(int i=0;i<v.size(); ++i){
            if(i>0) ans << " ";
            ans << v[i];
        }

        return ans.str();
    }
};


int main (){


    
}
