/*
Inorder traversal (Left → Node → Right) iteratively involves:

Traverse left as far as possible, pushing nodes on the stack.

Pop a node from the stack, visit it.

Move to the right subtree of the visited node.

*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
          vector<int>v ;
          stack<TreeNode*>s;
          TreeNode*curr = root;
          while(curr || !s.empty()){
            // left 
            while(curr){
                s.push(curr);
                curr=curr->left;
            }
            curr = s.top();
            s.pop();
            v.push_back(curr->val);
            curr = curr->right;
          } 
          return v ; 
        }
    };