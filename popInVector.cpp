#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    cout << "Before pop_back: ";
    for (int x : v) cout << x << " "; // 10 20 30
    cout << endl;

    // Get last element before removing
    int lastElement = v.back();
    v.pop_back(); // Remove last element

    cout << "Popped element: " << lastElement << endl;

    cout << "After pop_back: ";
    for (int x : v) cout << x << " "; // 10 20
    cout << endl;

    return 0;
}
