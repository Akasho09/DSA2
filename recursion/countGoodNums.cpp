#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

long long modPow(long long base, long long exp) {
    if (exp == 0) return 1;
    long long half = modPow(base, exp / 2);
    long long result = (half * half) % MOD;
    if (exp % 2 == 1) result = (result * base) % MOD;
    return result;
}

int countGoodNumbers(long long n) {
    long long even = n / 2;
    long long odd = (n + 1) / 2;
    return (modPow(5, odd) * modPow(4, even)) % MOD;
}

int main (){

    
}