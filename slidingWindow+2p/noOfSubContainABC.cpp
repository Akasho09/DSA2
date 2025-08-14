#include <iostream>
using namespace std;



int main (){

    
}

int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = n*(n+1)/2;
        bool a = false ;
        bool b = false ;
        bool c = false ;
        int tempLeft = 0;

        int right = 0 , left = 0;
        while(right<n){
            char t = s[right];

            if((a && b ) && c){ 
                a=false; b=false; c=false;
            char t1 = s[tempLeft];
                left = tempLeft;
            if(t1=='a') a=true;
            else if(t1=='b') b=true;
            else c=true;
            }
            
            if(t=='a') a=true;
            else if(t=='b') b=true;
            else c=true;
            if(right>0 && s[right]!=s[right-1]) tempLeft=right;

            ans-=(right-left+1);
            right++;
        }

        return ans ;
    }




    int numberOfSubstrings2(string s) {
        int n = s.size();
        int ans = 0;
        vector<int>lastSeen(3,-1);

        for(int i=0;i<n;i++){
            lastSeen[s[i]-'a']=i;
        if(lastSeen[0]!=-1 && lastSeen[1]!=-1 && lastSeen[2]!=-1){
            int minLast = min (min(lastSeen[0] , lastSeen[1]), lastSeen[2]);
            ans+=(minLast+1);
        }
        }

        return ans ;
    }
