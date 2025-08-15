#include <iostream>
using namespace std;


int main (){




}


 // Run-length encoding (RLE)
    string countAndSay(int n) {
        string result = "1";
        for (int step = 2; step <= n; step++) {
            string current = "";
            int count = 1;
            for (int i = 1; i <= result.size(); i++) {
                if (i < result.size() && result[i] == result[i - 1]) {
                    count++;
                } else {
                    current += to_string(count) + result[i - 1];
                    count = 1;
                }
            }
            result = current;
        }
        return result;
    }