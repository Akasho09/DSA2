#include <iostream>
using namespace std;


// stack using 1 queue
class MyStack {
    public:
    queue<int>q1;

        MyStack() {
               
        }
        
        void push(int x) {
            q1.push(x);
        }

        int pop(){
            int s = q1.size();
            for(int i=0;i<s-1;i++){
                q1.push(q1.front());
                q1.pop();
            }
            int res = q1.front();
            q1.pop();
            return res ;
        }

        int top(){
            int s = q1.size();
            for(int i=0;i<s-1;i++){
                q1.push(q1.front());
                q1.pop();
            }
            int res = q1.front();
            q1.push(res);
            q1.pop();
            return res ;
        }

        bool empty() {
            return q1.empty();
        }
    };


class MyStack {
    public:
    queue<int>q1;
    queue<int>q2;
        MyStack() {
               
        }
        
        void push(int x) {
            if(!q2.empty()){
                int temp = q2.front();
                q1.push(temp);
                q2.pop();
            }
            q2.push(x);
        }
        
        int pop() {
            int temp = q2.front();
            q2.pop();
            for(int i=0;i<q1.size()-1;i++){
                q2.push(q1.front());
                q1.pop();
            }
            q1.swap(q2);
            return temp;
        }
        
        int top() {
            return q2.front();
        }
        
        bool empty() {
            return q2.empty();
        }
    };

    class MyStack {
        public:
            queue<int> que1;
            queue<int> que2;
        
            MyStack() {}
            
            void push(int x) {
                que2.push(x);
        
                while(!que1.empty()){
                    que2.push(que1.front());
                    que1.pop();
                }
        
                swap(que1, que2);
            }
            
            int pop() {
                int result = que1.front();
                que1.pop();
        
                return result;
            }
            
            int top() {
                return que1.front();
            }
            
            bool empty() {
                return que1.empty();
            }
        };



int main (){


    
}