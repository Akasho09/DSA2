/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects
of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.
*/

#include <iostream>
using namespace std;

void sortColors(vector<int> &nums)
{
    int l = 0;
    int r = nums.size() - 1;
    while (l < r)
    {
        if (nums[l] != 0)
        {
            while (nums[r] != 0)
            {
                r--;
            }
            if (l < r)
                swap(nums[l], nums[r]);
        }
        l++;
        cout << l << endl;
    }

    l = 0;
    r = nums.size() - 1;
    while (l < r)
    {
        if (nums[l] == 2)
        {
            while (nums[r] != 1)
            {
                r--;
            }
            if (l < r)
                swap(nums[l], nums[r]);
        }
        l++;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

// Dutch National Flag
/*
✅ Time Complexity: O(n)

✅ Space Complexity: O(1) (in-place)
*/

void sortColors2(vector<int> &nums){
    
    int low, high, c;
    c = nums.size();
    low = 0;
    high = c - 1;
    for (int i = 0; i < c; i++)
    {
        if (nums[i] == 0)
        {
            swap(nums[low], nums[i]);
            low++;
        }
        else if (nums[i] == 2)
        {
            swap(nums[high], nums[i]);
            high--;
            i--;
            c--;
        }
    }
}

int main()
{

    vector<int> nums = {2, 0, 2, 1, 1, 0};

    sortColors(nums);
}