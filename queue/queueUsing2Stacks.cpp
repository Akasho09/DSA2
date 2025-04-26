#include <iostream>
using namespace std;

class MyQueue {
    public:

    stack<int>s1 ;
    stack<int>s2;
    
        MyQueue() {
            
        }
        
        void push(int x) {
           if(s2.empty()) s2.push(x); else s1.push(x);
        }
        
        int pop() {
            int res = s2.top();
            s2.pop();
            int s = s1.size();
            for(int i=0;i<s;i++){
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(s2.top());
            s2.pop();
            return res ;
        }
        
        int peek() {
            return s2.top();
        }
        
        bool empty() {
           return s2.empty(); 
        }
    };


    // queue using amortized method (O(1) comppexity ) .
    // s2 is upadated ony when empty , by reverse os s1 elements. 
    class MyQueue {
        public:
            stack<int> s1, s2;
        
            MyQueue() {
            }
            
            void push(int x) {
                s1.push(x);
            }
            
            int pop() {
                if (s2.empty()) {
                    while (!s1.empty()) {
                        s2.push(s1.top());
                        s1.pop();
                    }
                }
                int temp = s2.top();
                s2.pop();
                return temp;
            }
            
            int peek() {
                if (s2.empty()) {
                    while (!s1.empty()) {
                        s2.push(s1.top());
                        s1.pop();
                    }
                }
                return s2.top();
            }
            
            bool empty() {
                return s1.empty() && s2.empty();
            }
        };
        


int main (){


    
}