#include <iostream>
using namespace std;

class Solution {
    public:
        bool isValid(string s) {
            stack<int> st ;
        for(int i=0;i<s.size();i++){
            int temp = int(s[i]);
            if(temp==40 || temp==91 || temp==123) st.push(temp);
            else {
                if(st.empty()) return false ;
                int stop=int(st.top()); st.pop();
                if(temp-stop==1 || temp-stop==2) continue ;
                else return false;
            }
            }  
        if(st.size()==0) return true;
        else return false;
        }
    }; 

int main (){


    
}
