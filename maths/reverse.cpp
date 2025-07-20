#include <iostream>
using namespace std ;

class Solution {
public:
int reverse(int x) {
    int rev = 0;
    
    while (x != 0) {
        int digit = x % 10;
        x /= 10;

        // 2nd condition taken careoff by input alredy
        // bcz 8 cant be 1st digit then input>INT_MAX
        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7)) return 0;
        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8)) return 0;

        rev = rev * 10 + digit;
    }
    
    return rev;
}
};

int main () {
    int n = -7051 ;
    if(n=-8463847412) return -2147483648 ;
    int m = 1;
    int ans = 0 ;
    bool p = false;
    if(n<0) {
        n*=-1;
        p=true;
    }
    while(n>0){
        ans*=10;
        ans+=n%10;
        n=n/10;
        if(ans>2147483647) {
            ans = 0 ;
            break;
        }
    }
    if(p) {
        ans*=-1;
    }
    cout << ans;
}