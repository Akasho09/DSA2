/*
Problem Statement: You are given a read-only array of N integers with values also in the 
range [1, N] both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. 
The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.
*/

/*
✅ Approach: Mathematical Method
Let:

S = 1 + 2 + ... + N = N(N + 1)/2

S2 = 1² + 2² + ... + N² = N(N + 1)(2N + 1)/6

Let:

sum_arr = sum of all elements in the array

sum_sq_arr = sum of squares of all elements in the array

Let:

A - B = sum_arr - S = diff

A² - B² = sum_sq_arr - S2 = sq_diff
*/


// maths 


/*
✅ Use 1LL when:
You're multiplying large integers.

You're calculating sums/products involving n * n, n * (n + 1), etc.

You want to ensure long long arithmetic is used.

*/


/*
✅ Approach 2: XOR Method (Optimal: O(N) Time, O(1) Space)

Idea:
1. XOR all elements of the array and XOR all numbers from 1 to N.
This gives A ^ B (because all other numbers cancel out).

2. Use the rightmost set bit of A ^ B to divide numbers into 2 groups:
- One group has the repeating number,
- The other has the missing number.


{ 
basically divide nums into 2 groups such that repetaive and mising seprate and we do that by 
&ing with the differntiating bit in the 2 (XOR of 2 nums is!=0 => atleast 1 differntiating bit ) 
}

*/

#include <iostream>
using namespace std;


    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int N = n * n; // Total numbers expected

        long long actualSum = 0, actualSqSum = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int val = grid[i][j];
                actualSum += val;
                actualSqSum += 1LL * val * val;
            }
        }

        long long expectedSum = 1LL * N * (N + 1) / 2;
        long long expectedSqSum = 1LL * N * (N + 1) * (2 * N + 1) / 6;

        long long diff = actualSum - expectedSum;              // A - B
        long long sqDiff = actualSqSum - expectedSqSum;        // A^2 - B^2

        long long sumAB = sqDiff / diff;                       // A + B

        int A = (diff + sumAB) / 2; // Repeated
        int B = A - diff;           // Missing

        return {A, B};
    }

    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        int n = grid.size();
        int N = n * n;
        int xoor = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                xoor^=grid[i][j];
                xoor^=(1+i+(n*j));
            }
        }


        int setBit = xoor & -xoor;

        int zeroSet=0;
        int oneSet=0;


       for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {

                if( grid[i][j] & setBit ){
                    oneSet^=grid[i][j];
                }else {
                    zeroSet^=grid[i][j];
                }

                if( (1+i+(n*j)) & setBit ){
                    oneSet^=(1+i+(n*j));
                }else {
                    zeroSet^=(1+i+(n*j));
                }
            }
        }


            for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(grid[i][j]==zeroSet) return {zeroSet , oneSet} ;
                if(grid[i][j]==oneSet) return {oneSet , zeroSet  } ;
            }
        }
    }

int main (){

int xorAll = 8 ;
    cout << (xorAll & -xorAll);
    
}
