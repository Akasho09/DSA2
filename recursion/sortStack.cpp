// Given a stack, the task is to sort it such that the top of the stack has the greatest element.
#include <iostream>
using namespace std;


        void mergeee(vector<int>& v , int s , int m , int e){
        int i = s;
        int j = m+1;
        vector<int>t;

        while(i<=m && j<=e){
            if(v[i]<v[j]) t.push_back(v[i++]);
            else t.push_back(v[j++]);
        }

        while(i<=m) t.push_back(v[i++]);
        while(j<=e) t.push_back(v[j++]);
        for (int k = 0; k < t.size(); ++k) v[s + k] = t[k];

    }

    void mergeSortt(vector<int>& v , int s , int e){
        if(s>=e) return ; 
        int mid = s+(e-s)/2;
        mergeSortt(v , s , mid);
        mergeSortt(v , mid+1 , e);
        mergeee(v, s , mid , e);
    }

    void sortStack(stack<int> &st) {
        vector<int>v ;
        while(st.top()){
            v.push_back(st.top());
            st.pop();
        }
        mergeSortt(v , 0 , v.size()-1);
       
        for(int i=0;i<v.size();i++) st.push(v[i]);

    }

int main (){


}