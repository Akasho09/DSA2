
#include <iostream>
using namespace std;



int main (){

    
}

    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();
        vector<int>first(n+1,0); 
        vector<int>last(n+1,0);

        for(int i=0;i<n;i++){
            first[i+1]=first[i]+cardPoints[i];
            last[i+1]=last[i]+cardPoints[n-i-1];
        }

        int ans = 0;
        int left = 0;
        int right = k;
        while(right>=0){
            ans = max( ans , first[right]+last[left]);
            left++;
            right--;
        }

       return ans; 
    }



    int maxScore2(vector<int>& cardPoints, int k) {

        int sum = 0;
        int n = cardPoints.size();

        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }

        int ans = sum;
        for(int i=1;i<=k;i++){
            sum-=cardPoints[k-i];
            sum+=cardPoints[n-i];
            ans = max(ans,sum);
        }

       return ans; 
    }