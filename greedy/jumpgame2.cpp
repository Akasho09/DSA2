#include <iostream>
using namespace std;


int main (){




}

// range of ans type 
// similare to  DSA2/greedy/validParenthesis.cpp

   int jump(vector<int>& nums) {
        int n = nums.size();
        int high = 0 ; int jumps = 0 ;
        int end  = 0;

        for(int i=0;i<n;i++){
            high = max(high , i+nums[i]);
            if(end==i){
                jumps++;
                end = high;
            }
        }
        
       return jumps; 
    }