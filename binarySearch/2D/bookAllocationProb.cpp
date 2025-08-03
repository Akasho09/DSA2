class Solution {
public:

    bool possAns(vector<int> &nums, int k, int m) {
        int pages = 0;
        int students = 1;  // at least one student is needed

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > m) return false; // Can't assign a book bigger than m
            if(pages + nums[i] > m) {
                students++;
                pages = nums[i];
            } else {
                pages += nums[i];
            }
        }

        return students <= k;
    }

    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if(k > n) return -1; // Not enough books for each student

        int s = *max_element(arr.begin(), arr.end());
        int e = accumulate(arr.begin(), arr.end(), 0);
        int ans = -1;

        while(s <= e){
            int m = s + (e - s) / 2;
            if(possAns(arr, k, m)) {
                ans = m;
                e = m - 1;  // try for a better (smaller) answer
            } else {
                s = m + 1;
            }
        }

        return ans;
    }
};
