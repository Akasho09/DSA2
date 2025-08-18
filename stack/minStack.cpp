#include <iostream>
using namespace std;


int main (){




}


class MinStack {
public:
    MinStack() {

    }
      stack<int>a;
      stack<int> minSt; 

    void push(int val) {
        a.push(val);
        if(minSt.empty()) minSt.push(val);
        else minSt.push(min(val, minSt.top())); // imp
    }
    
    void pop() {
       a.pop(); minSt.pop();
    }
    
    int top() {
        return a.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};