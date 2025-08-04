
#include <iostream>
using namespace std;

class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        int n = a.size();
        int m = b.size();
        if (n > m) return kthElement(b, a, k);  // ensure a is the smaller array

        int s = max(0, k - m), e = min(k, n);

        while (s <= e) {
            int i = s + (e - s) / 2;
            int j = k - i;

            int l1 = (i == 0) ? INT_MIN : a[i - 1];
            int r1 = (i == n) ? INT_MAX : a[i];
            int l2 = (j == 0) ? INT_MIN : b[j - 1];
            int r2 = (j == m) ? INT_MAX : b[j];

            if (l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            } else if (l1 > r2) {
                e = i - 1;
            } else {
                s = i + 1;
            }
        }

        return -1; // unreachable if k is valid
    }
};




int main (){


    
}
