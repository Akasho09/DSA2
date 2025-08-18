// Infix to Post and Prefix

#include <iostream>
using namespace std;


int main (){




}

    int precedence (char p){
        if(p=='^') return 3;
        if(p=='*' || p=='/') return 2;
        if(p=='+' || p=='-') return 1;
            return -1;
    }


    /**/
    string infixToPrefix(string s) {
   
    reverse(s.begin(),s.end());
    for(char &c : s) {
        if(c == '(') c = ')';
        else if(c == ')') c = '(';
    }
        string result = "";
        stack<char>st;
        for(char c : s){
            if(c=='('){
              st.push(c); 
            } else if(c==')'){
                while(!st.empty() && st.top()!='('){
                    result+=st.top(); st.pop();
                }
            if(!st.empty()) st.pop(); 
            } else if(precedence(c)==-1){
               result+=(c); 
            }else {
                if(c=='^'){
                    while(!st.empty() && precedence(c)<=precedence(st.top())){
                    result+=st.top(); st.pop();
                }
                }else {
                    while(!st.empty() && precedence(c)<precedence(st.top())){
                    result+=st.top(); st.pop();
                }
                }
                st.push(c);
            }
        }
            while(!st.empty()){
                result+=st.top(); st.pop();
            }
            
            reverse(result.begin(),result.end());
            
        return result;
    }

    string infixToPostfix(string& s) {
        stack<char>st ;
        string result = "";
        
        for(char c : s){
            if(c=='('){
              st.push(c);  
            }else if(c==')'){
                while(!st.empty() && st.top()!='('){
                    result+=(st.top()); st.pop();
                }
                st.pop();
            } else if(precedence(c)==-1){
                result+=c;
            } else {
                while(!st.empty() && precedence(c)<=precedence(st.top())){
                    result += st.top(); st.pop();
                }
                st.push(c);
            }
        }
            
        while(!st.empty()){
            result += st.top(); st.pop();
        }
        return result;
    }