
#include <iostream>
using namespace std;

    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int s = 0;
        int e = n - 1;

        while (s <= e) {
            int m = s + (e - s) / 2;
            int missing = arr[m] - (m + 1);
            if (missing < k) {
                s = m + 1;
            } else {
                e = m - 1;
            }
        }

        return s + k;
    }



int main (){


    
}
