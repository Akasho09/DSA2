#include <iostream>
using namespace std;


int main (){




}

    // 2pointer approach
    int trap(vector<int>& height) {
         int n = height.size();
         int r=n-1,l=0,ans=0 , leftMax=0 , rightMax=0;
         while(l<r){
            if(height[l]<=height[r]){
                if(height[l]<leftMax){
                    ans+=(leftMax-height[l]);
                } else leftMax=height[l];
                l++;
            } else {
                if(height[r]<rightMax){
                    ans+=(rightMax-height[r]);
                } else rightMax=height[r];
                r--;
            }
         }

         return ans ;
    }

    // leftMax n RightMax approach
    int trap(vector<int>& height) {
         int n = height.size();

         vector<int>lMax(n) , rMax(n);

         lMax[0]=height[0]; rMax[n-1]=height[n-1];
         for(int i=1;i<n;i++){
            lMax[i]=max(lMax[i-1],height[i]);
            rMax[n-i-1]=max(rMax[n-i],height[n-i-1]);
         }

         int ans = 0 ;
         for(int i=0;i<n;i++){
            ans+=(min(lMax[i],rMax[i])-height[i]);
         }

         return ans ;
    }