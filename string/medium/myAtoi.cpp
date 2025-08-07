#include <iostream>
#include <vector>
#include <string>

using namespace std ;


// errors
   int myAtoi(string s) {
 
        int n = s.size();
        int i = 0;
        bool signn = false ;
            int ans = 0 ;
            while(i<n && s[i]==32) i++;
            if(i<n && s[i]=='-') { signn = true ; i++; }
            else if(i<n && s[i]=='+') { i++; }
            while(i<n && s[i]==48) i++;
        while(i<s.size()){
            if(s[i]>57 || s[i]<48){
                     if(signn) return -(ans);
                     return ans ;
            } else {
                if(ans>=INT_MAX/10){ 
                    if(i==n-1 && s[i]<'8'){ 
                        if(signn) return -2147483640-(s[i]-'0');
                        return 2147483640+(s[i]-'0');
                    }
                    if(signn) return INT_MIN;
                    return INT_MAX;
                }
                ans*=10; ans+=(s[i]-'0');
            }
            i++;
        }
        if(signn) return -(ans);
        return ans ;
    }

    int myAtoi2(std::string s) {
    int i = 0, n = s.length();
    long ans = 0;
    int sign = 1;

    while (i < n && s[i] == ' ') i++;

    if (i < n && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    while (i < n && s[i] == '0') i++;

    while (i < n && isdigit(s[i])) {
        ans = ans * 10 + (s[i] - '0');

        if (sign == 1 && ans > INT_MAX) return INT_MAX;
        if (sign == -1 && -ans < INT_MIN) return INT_MIN;

        i++;
    }

    return static_cast<int>(sign * ans);
}

int main() {
    std::vector<std::pair<std::string, int>> testCases = {
        {"42", 42},
        {"    -42", -42},
        {"4193 with words", 4193},
        {"words and 987", 0},
        {"-91283472332", -2147483648},
        {"3.14159", 3},
        {"+1", 1},
        {"00000-42a1234", 0},
        {"   +0 123", 0},
        {"21474836460", 2147483647},
        {"-2147483649", -2147483648},
        {"   +004500", 4500},
        {"", 0},
        {"+", 0},
        {"-", 0},
        {"2147483642", 2147483642},
        {"-2147483642", -2147483642},
        {"  0000012345", 12345},
        {"  -0000000000012345abc", -12345},
        {"   +123abc456", 123},
        {"--123", 0},
        {"++123", 0},
        {"-+12", 0},
        {"+-12", 0},
        {"-2147483648", -2147483648},
        {"2147483647", 2147483647},
        {"2147483800" , 2147483647},
        {"2147483657" , 2147483647},
        {"2147483832" , 2147483832}
    };

    for (const auto& [input, expected] : testCases) {
        int result = myAtoi(input);
        std::cout << "Input: \"" << input << "\"\tExpected: " << expected << "\tGot: " << result
                  << (result == expected ? " ✅" : " ❌") << '\n';
    }

    return 0;
}
