
#include <iostream>
using namespace std;

int main (){




}



class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string result;
        
        // Handle sign
        if ((numerator < 0) ^ (denominator < 0)) result += "-";

        // Use long long to prevent overflow
        long long num = llabs((long long)numerator);
        long long den = llabs((long long)denominator);

        // Integer part
        result += to_string(num / den);
        long long remainder = num % den;

        if (remainder == 0) return result; // no fractional part

        result += "."; // decimal point

        unordered_map<long long, int> remainderPos;
        while (remainder != 0) {
            if (remainderPos.count(remainder)) {
                // repeating part detected
                result.insert(remainderPos[remainder], "(");
                result += ")";
                break;
            }

            remainderPos[remainder] = result.size();
            remainder *= 10;
            result += to_string(remainder / den);
            remainder %= den;
        }

        return result;
    }
};

