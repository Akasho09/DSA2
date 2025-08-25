#include <vector>
using namespace std;

bool isTrionic(vector<int>& nums) {
    int n = nums.size();
    if (n < 4) return false; // need at least 4 elements

    int i = 0;

    // Step 1: strictly increasing
    while (i + 1 < n && nums[i] < nums[i + 1]) i++;
    if (i == 0 || i == n - 1) return false; // must increase at least once

    // Step 2: strictly decreasing
    int p = i;
    while (i + 1 < n && nums[i] > nums[i + 1]) i++;
    if (i == p || i == n - 1) return false; // must decrease at least once

    // Step 3: strictly increasing again
    int q = i;
    while (i + 1 < n && nums[i] < nums[i + 1]) i++;
    if (i == q || i != n - 1) return false; // must increase again till end

    return true;
}
