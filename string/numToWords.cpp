#include <iostream>
using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        if(num==0) return "Zero";
string ones[21] = { 
    "Zero ", "One ", "Two ", "Three ", "Four ", "Five ", 
    "Six ", "Seven ", "Eight ", "Nine ", "Ten ", 
    "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", 
    "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen ", "Twenty "
};

string tens[10] = { 
    "", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", 
    "Sixty ", "Seventy ", "Eighty ", "Ninety " 
};

int counts[5] = { 1, 100, 1000, 1000000, 1000000000 };

string countsCorrs[5] = {
    "", "Hundred ", "Thousand ", "Million ", "Billion " 
};

        string ans = "";
        int i = 4;
        while(i>=0){
            if(num>=counts[i]){
                int b = num/counts[i]; // 1-999
                num = num % counts[i];
                if(b>=100){
                    int h = b/100;
                    if(h!=0) ans+=ones[h]; 
                    ans+="Hundred ";
                    b=b%100;
                }
                if(b>20){
                    int t = b/10;
                    ans+=tens[t] ;
                    b=b%10;
                    if(b>0) { ans+=(ones[b]);  }
                } else if(b!=0) {
                  ans+=(ones[b]); 
                }

                if(i>0) ans+=(countsCorrs[i]);
            } else i--;
        }

        if(ans.back()==' ') return ans.substr(0,ans.size()-1);
        return ans ;
    }

    // ✅ Known-correct recursive version for verification
    string helper(int num) {
        vector<string> below20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                                  "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                                  "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        
        if (num == 0) return "";
        else if (num < 20) return below20[num] + " ";
        else if (num < 100) return tens[num/10] + " " + helper(num%10);
        else return below20[num/100] + " Hundred " + helper(num%100);
    }

    string trustedNumberToWords(int num) {
        if (num == 0) return "Zero";
        return trim(helperBig(num));
    }

private:
    string helperBig(int num) {
        if (num >= 1000000000) return helper(num/1000000000) + "Billion " + helperBig(num%1000000000);
        else if (num >= 1000000) return helper(num/1000000) + "Million " + helperBig(num%1000000);
        else if (num >= 1000) return helper(num/1000) + "Thousand " + helperBig(num%1000);
        else return helper(num);
    }

    string trim(string s) {
        while (!s.empty() && s.back() == ' ') s.pop_back();
        return s;
    }
};


int main() {
    Solution sol;
    
    vector<int> tests = {
        // ✅ Small numbers
        0, 1, 2, 9, 10, 11, 15, 19, 20, 21, 25, 30, 45, 50, 70, 99,

        // ✅ Hundreds
        100, 101, 110, 115, 123, 200, 305, 512, 999,

        // ✅ Thousands
        1000, 1001, 1010, 1100, 1234, 2005, 9999, 15000, 54321, 99999,

        // ✅ Hundred-thousands
        100000, 100001, 123456, 500999, 999999,

        // ✅ Millions
        1000000, 1000001, 1234567, 9000000, 5000500, 9999999,

        // ✅ Tens/hundreds of millions
        100000000, 123456789, 987654321,

        // ✅ Billions
        1000000000, 1234567890, 2000000001, 2147483647 // INT_MAX
    };

    for (int num : tests) {
        string mine = sol.numberToWords(num);
        string trusted = sol.trustedNumberToWords(num);
        cout << num << " -> " << mine 
             << " | Trusted: " << trusted
             << (mine == trusted ? " ✅" : " ❌") 
             << endl;
    }
    return 0;
}
