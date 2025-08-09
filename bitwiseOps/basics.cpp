
#include <iostream>
using namespace std;

    bool checkIthBit(int n, int i) {
        return n&(1<<i);
    }

    bool isEven(int n) {
        return (1&n)==0;
    }

    bool isPowerofTwo(int n) {
        bool ans = false ;
        while(n>0){
            if(n&1) {
                if(ans) return false ;
            ans = true;
            }
            n=n>>1;
        }
        return true;
    }

     bool isPowerofTwo(int n) {
      return (n>0) && (n&(n-1))==0;
    }


    pair<int, int> get(int a, int b) {
        a=a^b;
        b=a^b;
        a=a^b;
        return {a,b};
    }


    int minBitFlips(int start, int goal) {
        int xorr = start^goal;
        int ans = 0;
        while(xorr){
            xorr = xorr&(xorr-1);
            ans++;
        }
        return ans ;
    }
    
int main (){

    
}