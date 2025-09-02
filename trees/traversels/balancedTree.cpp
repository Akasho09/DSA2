
class Solution {
public:
    int helper(TreeNode* root){
        if(!root) return 0 ;
        int l = 0 ,  r = 0 ;
        if(root->left) l =  helper(root->left);
        if(root->right) r =  helper(root->right);
        if(l==-1 || r==-1) return -1;

        if(abs(l-r) > 1) return -1;

     return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        return helper(root)!=-1;
    }
};