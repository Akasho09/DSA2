
#include <iostream>
using namespace std;


// using recursion
double myPow(double x, int n) {
    if(n==0) return 1.0;

    if(n<0){
        if(n==INT_MIN) return 1.0/(x*myPow(x,-(n+1)));
        return 1.0/myPow(x,-n);
    }

    double half = myPow(x, n / 2);
    if (n % 2 == 0)
        return half * half;
    else
        return x * half * half;
    
}


    double myPow2(double x, int n) {
        long long exp = n;
        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }

        double result = 1.0;
        while (exp > 0) {
            if (exp & 1) result *= x;
            x *= x;       // square the base
            exp >>= 1;    // shift right (divide exponent by 2)
        }
        return result;
        
    }


int main (){

    
}