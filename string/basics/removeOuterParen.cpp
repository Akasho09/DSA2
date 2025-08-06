#include <iostream>
using namespace std;

std::string removeOuterParentheses(const std::string& s) {
    std::string result;
    int depth = 0;

    for (char ch : s) {
        if (ch == '(') {
            if (depth > 0) {
                result += ch;
            }
            depth++;
        } else if (ch == ')') {
            depth--;
            if (depth > 0) {
                result += ch;
            }
        }
    }

    return result;
}

   string removeOuterParentheses2(string s) {
        int open = 1 ;
        int ind = 0 ;
        string ans = "";
        
        for(int i=1;i<s.size();i++){ 
            if(s[i]=='(') open++;
            else open--;

            if(open==0){
                ans+=s.substr(ind+1,i-ind-1);
                ind = i+1 ;
            }  
        }
        return ans;
    }


int main (){


    
}
