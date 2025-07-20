/*
✅ Key rules:
Negative numbers are not palindromes (e.g. -121 ≠ 121-).

Numbers ending with 0 (but not 0 itself) can't be palindromes (e.g. 10 ≠ 01).


*/ 

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x%10==0 && x!=0)) return false ;

        int rev = 0;

        while(x>rev){
            rev*=10;
            rev+=x%10;
            x=x/10;
        }

        
        if(x==rev || x == rev/10) return true;
        return false ;

    }
};