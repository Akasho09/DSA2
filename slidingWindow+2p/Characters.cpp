
#include <iostream>
using namespace std;


    int characterReplacement(string s, int k) {
        vector<int>count (26 , 0 );
        int n = s.size();
        int ans = 0 , left = 0 , maxOcc = 0;

        for(int i=0;i<n;i++){
            count[s[i]-'A']++;

            if(count[s[i]-'A']>maxOcc) maxOcc=count[s[i]-'A'];
            if((i-left+1-maxOcc)>k){
                count[s[left]-'A']--;
                left++;
            }

            ans= max(ans,i-left+1);
        }
        return ans ;
    }


int main (){

    
}