#include <iostream>
using namespace std;

int main (){



}



struct TreeNode {
    int val;
 TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



class Solution {
public:
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        if (root == p || root == q) return root; 

        TreeNode* left = helper(root->left, p, q);
        TreeNode* right = helper(root->right, p, q);

        if (left && right) return root; 
        return left ? left : right; 
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root, p, q);
    }
};
