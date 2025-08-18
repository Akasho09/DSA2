//  post, pre to Infix

#include <iostream>
using namespace std;

bool isOp(char c) {
    return (c=='/' || c=='*' || c=='+' || c=='-' || c=='^');
}

string postToInfix(string exp) {
    stack<string> st;
    
    for(char c : exp) {
        if(isOp(c)) {
            if(st.size() < 2) return "Invalid Postfix Expression";
            
            string right = st.top(); st.pop();
            string left  = st.top(); st.pop();
            
            string expr = "(" + left + c + right + ")";
            st.push(expr);
        } else {
            string t(1, c);
            st.push(t);
        }
    }
    
    if(st.size() != 1) return "Invalid Postfix Expression";
    return st.top();
}

     
string preToInfix(string pre_exp) {
        stack<string>s;
        
        for(int i=pre_exp.size()-1;i>=0;i--){
            if (isOp(pre_exp[i])){
                if(s.size()<2) return "Invalid Prefix Expression";
                string left = s.top();  s.pop();
                string right = s.top(); s.pop();
                left= "("+left+pre_exp[i]+right+")";
                s.push(left);
            } else {
                string t ="";
                t+=pre_exp[i];
                s.push(t);
            }
        }
        
        if(s.size() != 1) return "Invalid Prefix Expression";
        return s.top();
    }

int main (){

cout << postToInfix("ab*c+");

//         stack<string>s;
// s.push("s");
// s.top()=s.top()+"b";

// cout <<endl <<s.top();

}
