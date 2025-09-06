#include <iostream>
using namespace std;

int main (){



}


class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        long long maxWidth = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            long long firstIndex = q.front().second;
            long long lastIndex = q.back().second;
            maxWidth = max(maxWidth, lastIndex - firstIndex + 1);

            for (int i = 0; i < size; i++) {
                auto [node, index] = q.front();
                q.pop();

                long long curIndex = index - firstIndex;

                if (node->left) {
                    q.push({node->left, 2 * curIndex});
                }
                if (node->right) {
                    q.push({node->right, 2 * curIndex + 1});
                }
            }
        }

        return (int)maxWidth;
    }
};
