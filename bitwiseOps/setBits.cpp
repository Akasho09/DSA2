

#include <iostream>
using namespace std;

// Approach 1 — Shift & Count

    int hammingWeight(int n) {
        int count = 0;
        while (n > 0) {
            if (n & 1) count++;
            n >>= 1; // shift right
        }
        return count;
    }

// Approach 2 — Brian Kernighan’s Algorithm (Faster)


    int hammingWeight2(int n) {
        int count = 0;
        while (n > 0) {
            n &= (n - 1); // remove the lowest set bit
            count++;
        }
        return count;
    }


    

int main (){

    
}