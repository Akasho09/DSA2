// Post to Pre and Pre to Post

#include <iostream>
using namespace std;


int main (){




}

    string preToPost(string pre_exp) {
        stack<string>s ;
        
        for(int i=pre_exp.size()-1;i>=0;i--){
            if(isOp(pre_exp[i])){
                if(s.size()<2) return "Inavlid pre_exp";
                string left = s.top(); s.pop();
                string right = s.top() ; s.pop();
                left+=right+ pre_exp[i];
                s.push(left);
            }else {
                string t = ""; t+=pre_exp[i];  
                s.push(t);
            }
        }
         if(s.size()!=1) return "Inavlid pre_exp";
         return s.top();
    }

    bool isOp(char c) {
    return (c=='/' || c=='*' || c=='+' || c=='-' || c=='^');
    }
    string postToPre(string post_exp) {
        // Write your code here
        stack<string>s ;
        
        for(char c: post_exp){
            if(isOp(c)){
                if(s.size()<2){
                    return "Invalid post_exp ";
                }
                string right = s.top(); s.pop();
                string left = s.top() ; s.pop();
                left= c+left+right;
                s.push(left);
            } else {
                string t = "";
                t+=c;
                s.push(t);
            }
        }
        
        if(s.size()!=1) return "Invalid post_exp ";

        return s.top();
    }