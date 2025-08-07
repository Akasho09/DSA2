
   #include <iostream>
using namespace std;

string longestPalindrome(string s) {
   int ans = 0 ;
   int upper = 0;
   int lower = 0;
   int n = s.size();

   for(int i=0;i<n;i++){
        int a = i-(ans/2)-1;
        int b = i+(ans/2)+1;
    if(i>0){
        while((a>=0 && b<n) && (s[a++]==s[b--])){
            if(a==i-1 && b==i+1){
        a = i-(ans/2)-2;
        b = i+(ans/2)+2;
        while((a>=0 && b<n) && (s[a--]==s[b++])){}
        if(b-a+1>ans )upper=b; lower=a;
        ans = max(ans , b-a+1);
    }
    }
    }
        a = i-(ans/2);
        b = i+(ans/2)+1;

        while((a>=0 && b<n) && (s[a++]==s[b--])){
        if(a==i && b==i+1){
        a = i-(ans/2)-1;
        b = i+(ans/2)+2;
        while((a>=0 && b<n) && (s[a--]==s[b++])){}
        if(b-a+1>ans )upper=b; lower=a;
        ans = max(ans , b-a+1);
    }
    }
   }


   return s.substr(lower,upper-lower+1) ;
   
}

class Solution {
public:
        int check (const string& s , int a , int b) {
            int n = s.size();
            while(a>=0 && b<n && s[a] == s[b]){
                a--; b++;
            }
            return b-a-1;
        }

string longestPalindrome2(string s) {
   int n = s.size();
   int start = 0, maxLen = 1;

   for(int i=0;i<n;i++){
    int small = min(i+1,n-i);

    if((small*2)>maxLen){
            int p = check(s,i-1,i+1);
            int q = check(s,i,i+1);

        if(p>maxLen){
            maxLen=p;
            start=i-(p/2);
        }   
        if(q>maxLen){
            maxLen=q;
            start=i-(q/2)+1;
        }
    }
    }

   return s.substr(start,maxLen) ;
}
};


int main (){

    
}