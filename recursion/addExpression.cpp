class Solution {
public:
    void helper(string &num, int target, int pos, long long sum, long long prev, string expr, vector<string> &ans) {
        if (pos == num.size()) {
            if (sum == target) ans.push_back(expr);
            return;
        }

        for (int len = 1; len <= num.size() - pos; len++) {
            // Avoid numbers with leading zero
            if (len > 1 && num[pos] == '0') break;

            string part = num.substr(pos, len);
            long long val = stoll(part);

            if (pos == 0) {
                // First number, no operator
                helper(num, target, pos + len, val, val, part, ans);
            } else {
                // Addition
                helper(num, target, pos + len, sum + val, val, expr + "+" + part, ans);

                // Subtraction
                helper(num, target, pos + len, sum - val, -val, expr + "-" + part, ans);

                // Multiplication (undo prev, apply multiplication)
                helper(num, target, pos + len, sum - prev + prev * val, prev * val, expr + "*" + part, ans);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        helper(num, target, 0, 0, 0, "", ans);
        return ans;
    }
};
