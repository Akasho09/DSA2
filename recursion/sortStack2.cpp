
#include <iostream>
using namespace std;

class SortedStack{
public:
    stack<int> s;
    void sort();
};

void helper(stack<int> &s , int t){
    if(s.empty() || s.top()<t){
        s.push(t);
        return;
    }
    
    int top = s.top();
    s.pop();
    helper(s,t);
    s.push(top);
}

void sortit(stack<int> &s){
    if(s.empty()) return ;
    int top=s.top();
    s.pop();
    sortit(s);
    helper(s,top);
}

void SortedStack::sort() {
    sortit(s);
}


int main (){

    
}