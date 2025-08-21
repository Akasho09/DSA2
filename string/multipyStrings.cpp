#include <iostream>
using namespace std;

int main (){




}


class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        if(num1=="1") return num2;
        if(num2=="1") return num1;

        int n = num1.size(), m = num2.size();
        string ans(n+m,'0');
        for(int i=m-1;i>=0;i--){
            int a = num2[i]-'0' ;
            int b = 0 ;
            for (int j=n-1;j>=0;j--){
                b+= ((num1[j]-'0')*a);
                b+=(ans[j+i+1]-'0');
                char temp = '0';
                temp+=(b%10);
                ans[j+i+1]=temp;
                b=b/10;
            }
            if(b!=0) ans[i]+=b;
        }

        if(ans[0]=='0') return ans.substr(1);
        return ans ;
    }
};