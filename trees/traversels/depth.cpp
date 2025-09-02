class Solution {
public:
    int helper(TreeNode* root){
        if(!root) return 0;
        
        int left = 0 , right = 0 ;
        if(root->left) left = helper(root->left);
        if(root->right) right = helper(root->right);

        return 1+max(left , right);
    }
    int maxDepth(TreeNode* root) {
        return helper(root);
    }
};