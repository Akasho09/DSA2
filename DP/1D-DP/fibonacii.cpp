#include <iostream>
using namespace std;

int fibHelper(int n, vector<int>& dp) {
    if (n <= 1) return n;  
    if (dp[n] != -1) return dp[n];
    return dp[n] = fibHelper(n-1, dp) + fibHelper(n-2, dp);
}

int fib(int n) {
    vector<int> dp(n+1, -1);
    return fibHelper(n, dp);
}

int main() {
    int n = 10;
    cout << "Fibonacci(" << n << ") = " << fib(n) << endl;
    return 0;
}
