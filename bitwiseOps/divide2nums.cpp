

#include <iostream>
using namespace std;

    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        if(dividend==INT_MIN && divisor==1) return INT_MIN;

        bool sign = false ;
        sign = (dividend<0) ^ (divisor<0) ;
        
        long long a = llabs((long long)dividend);
        long long b = llabs((long long)divisor);

        int ans = 0;

        for(int i=31;i>=0;i--){
            if((b<<i)<=a){
                a-=(b<<i);
                ans+=(1<<i);
            }
        }

        return sign ? -ans : ans;
    }

int main (){

    
}