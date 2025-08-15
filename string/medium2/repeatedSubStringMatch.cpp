#include <iostream>
using namespace std;


int main (){




}


// idiotic robin karp
    int repeatedStringMatch3(string a, string b) {
        int n = a.size() , m = b.size(); 
        int count = -1;

        int hashVal = 0 ;
        for(int i=0;i<n;i++){
            int val = a[i]%47;
           hashVal+=val; 
        }

        int curr = 0;
        for(int i=0;i<n;i++){
            int val = b[i]%47;
           curr+=val; 
        }

        for(int i=0;i<n;i++){
            
            if(curr==hashVal && a[0]==b[i]){
                int j=0;
                int left = n-i; count = 1; 
                for(;j<m;j++){
                    if(left>=n) { left=left%n; count++; }
                    if(a[left]!=b[j]) break;
                    left++; 
                }
                if(j==m) return count;
            } else {
           int val = b[i+n]%47;
           curr+=val; 
           val = b[i]%47;
           curr-=val; 
            }
        }

        return -1; 
    }

    int repeatedStringMatch2(string a, string b) {
        int n = a.size(); 
        int t1=n;
        string t=a;

        int ans = 1;
        while(n<b.size()){ t+=a; ans++; n+=t1; }
        if(t.find(b) != -1) return ans ;

        t+=a; ans++;
        if(t.find(b) != -1) return ans ;

        return -1; 
    }

    int repeatedStringMatch(string a, string b) {
        int n = a.size() , m = b.size() ; 
        
        int left = 0 ;
        int right = 0 ;
        int ans = -1 ;
        while(left<n){
            if(a[left]==b[right]){
                ans = 1 ;
                int j =  left ;
                while(right<b.size()){
                    if(j>=n) { j=j%n; ans++; }
                     if(a[j]==b[right]){
                        j++;right++;
                     } else break ;
                }   
                if(right==m) return ans;
            }
            right = 0;
            left++;
        }
    return -1;
    }