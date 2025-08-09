#include <iostream>
using namespace std;

class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        vector<int>v ;
        v.push_back(1);
        vector<int>primes= {3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

        for(int i=0;i<nums.size();i++){

            if(nums[i]%2==0) v[0]=2;
            while(nums[i]%2==0) nums[i]/=2;

            for(int j=1;j<v.size();j++){
                while(nums[i]%v[j]==0) nums[i]/=v[j];
            }

            for(int j=0;j<primes.size();j++){
            if(nums[i]%primes[j]==0){
                    v.push_back(primes[j]);
                    while(nums[i]%primes[j]==0) nums[i]/=primes[j];
                }
            }   

            if(nums[i]>1) v.push_back(nums[i]);
        }

        if(v[0]==1) return v.size()-1;
        return v.size();
    }
};

class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> primes;

        for (int x : nums) {
            // Factor out 2 first
            if (x % 2 == 0) {
                primes.insert(2);
                while (x % 2 == 0) x /= 2;
            }
            // Factor out odd primes
            for (int p = 3; p * p <= x; p += 2) {
                if (x % p == 0) {
                    primes.insert(p);
                    while (x % p == 0) x /= p;
                }
            }
            // If remaining x > 1, it's a prime
            if (x > 1) primes.insert(x);
        }

        return primes.size();
    }
};




int main (){

    
}