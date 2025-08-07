#include <iostream>
#include <iomanip> // For precision

using namespace std;

void helper(double x, int n , double& ans ){
    if(n<1) return;
    if(n%2!=0) ans*=x;
    helper(x*x,n/2, ans);
}

double myPow(double x, int n) {
    if(n==0) return 1.0;
    double ans = 1;
    helper(x,n, ans);
    return ans ;
}


double myPow2(double x, int n) {
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

int main() {
    vector<pair<double, int>> testCases = {
        {2.0, 10},
        {2.0, -2},
        {2.0, 0},
        {3.0, 5},
        {5.5, 3},
        {0.5, 2},
        {2.0, -3},
        {1.0, INT_MAX},
        {-1.0, INT_MAX},
        {-2.0, 4},
        {-2.0, 3},
        {10.0, 6},
        {2.0, 31},
        {2.0, -31},
        {0.0, 5},
        {0.0, 0},
        {2.0, INT_MIN},
        {1.0001, 10000},
        {0.9999, 10000},
        {-0.9999, 10001},
        {-3.0, 0},
        {123.456, 1}
    };

    cout << fixed << setprecision(6);

    int caseNum = 1;
    for (auto [x, n] : testCases) {
        double expected = pow(x, n);  // Expected result using std::pow
        double actual = myPow2(x, n);
        bool isCorrect = fabs(expected - actual) < 1e-5;

        cout << "Test Case " << caseNum++ << ": myPow(" << x << ", " << n << ") = " << actual;
        cout << " | Expected: " << expected;
        cout << " | " << (isCorrect ? "✅ Correct" : "❌ Incorrect") << endl;
    }

    return 0;
}