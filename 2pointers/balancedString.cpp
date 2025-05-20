/*
 How It Works:
It tracks the current balance — increases for '[', decreases for ']'.

If balance goes negative, it means more ] have appeared than [, so we count the max imbalance.

Each swap fixes two positions, so ceil(maxImbalance / 2.0) is the answer.
*/
#include <iostream>
#include <string>
using namespace std;

int minSwaps(string s) {
    int balance = 0, maxImbalance = 0;

    for (char ch : s) {
        if (ch == '[') {
            balance++;
        } else {
            balance--;
        }

        // Track the maximum depth of imbalance
        if (balance < 0) {
            maxImbalance = max(maxImbalance, -balance);
        }
    }

    // One swap can fix two units of imbalance
    return (maxImbalance + 1) / 2;
}

int main() {
    string s;
    cout << "Enter the bracket string: ";
    cin >> s;

    cout << "Minimum swaps needed: " << minSwaps(s) << endl;
    return 0;
}
