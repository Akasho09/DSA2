#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;  // Empty vector, size = 0, capacity = 0 initially

    cout << "Initial size: " << v.size() << ", capacity: " << v.capacity() << endl;

    // Add elements one by one and print size & capacity
    for (int i = 1; i <= 10; ++i) {
        v.push_back(i);
        cout << "After adding element " << i 
             << " -> size: " << v.size() 
             << ", capacity: " << v.capacity() << endl;
    }

    return 0;
}
