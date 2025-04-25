#include <iostream>
using namespace std;

struct TreeNode {
    int val;
 TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    public:
       vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* curr = root;
        TreeNode* prev = nullptr;
    
        while (curr || !s.empty()) {
            // go as left as possible
            while (curr) {
                s.push(curr);
                curr = curr->left;
            }
    
            TreeNode* node = s.top();
    
            // if right is null or already visited
            if (node->right == nullptr || node->right == prev) {
                result.push_back(node->val);
                s.pop();
                prev = node;
            } else {
                curr = node->right;  // go to right child if added to stack if many ....
               
            }
        }
    
        return result;
    }
    
    };


    class Solution {
        public:
            vector<int> num={};
            vector<int> postorderTraversal(TreeNode* root) {
                if (root==nullptr)
                    return num;
                postorderTraversal(root->left);
                postorderTraversal(root->right);
                num.push_back(root->val);
                return num;
            }
        };

        

int main (){


    
}