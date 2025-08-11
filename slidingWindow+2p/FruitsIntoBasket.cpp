

#include <iostream>
using namespace std;

    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if(n<3) return n;
        int ans = 0;

        int ind = 0;
        int s = 0;
        int i=1;
        for(;i<n;i++){
            if(fruits[i]!=fruits[0]) break;
        }
        int e = i;

        for(;i<n;i++){
            if(fruits[i]==fruits[e]) continue;
            else if(fruits[i]==fruits[s]){
                s=e; e=i;
            } else {
                ans = max(ans , i-ind);
                s=e; ind=e; e=i; 
            }
        }

        ans = max(ans , n-ind);
        return ans ;

        }


int main (){

    
}