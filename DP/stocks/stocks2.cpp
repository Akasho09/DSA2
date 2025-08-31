#include <iostream>
using namespace std;

int main (){



}


    int maxProfit(vector<int>& prices) {
        int ans = 0 , n = prices.size();
        int mini = prices[0];

        for(int i=1;i<n;i++){
            if(prices[i]<prices[i-1]) {
                ans+=prices[i-1]-mini;
                mini=prices[i];
            }
        }

        if(prices[n-1]>mini) ans+=prices[n-1]-mini;

        return ans;


    }