// Sieve of Eratosthenes


#include <iostream>
using namespace std;

    int countPrimes(int n) {
        if (n <= 2) return 0; 

        vector<bool> isComposite(n, false);
        
        for (int i = 2; i * i < n; i++) {
            if (!isComposite[i]) {
                for (int j = i * i; j < n; j += i) {
                    isComposite[j] = true;
                }
            }
        }

        int count = 0;
        for (int i = 2; i < n; i++) {
            if (!isComposite[i]) count++;
        }
        return count;
    }


int main (){

    
}