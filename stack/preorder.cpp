/*
Given the root of a binary tree, return the preorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [1,2,3]
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
        vector<int> preorderTraversal(TreeNode* root) {
          vector<int> v;
          stack<TreeNode*>s;
          TreeNode*curr = root;

          while(curr || !s.empty()){
            while(curr){
                // push curr to ans , if right store in stack and then move to left if left is checked then by above condition .
                v.push_back(curr->val);
                s.push(curr->right);
                curr= curr->left;  // if
            }
            curr=s.top(); 
            s.pop();
          }
          return v;
        }
    };

    class Solution {
      public:
          vector<int>v = {};
          vector<int> preorderTraversal(TreeNode* root) {
              if(root==nullptr) return v;
              v.push_back(root->val);
              preorderTraversal(root->left) ;
              preorderTraversal(root->right) ;
              return v;
          
          }
    };
    
int main (){


    
}

  
