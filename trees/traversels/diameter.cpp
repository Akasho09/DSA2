class Solution {
public:
    int helper(TreeNode* root , int&d){
        if(!root) return 0 ;

        int l = 0 ,  r  = 0 ;
        if(root->left) l = helper(root->left , d);
        if(root->right) r = helper(root->right , d);
        d = max(d , l+r);
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
         int d  = 0;
         helper(root , d );
         return d;
    }
};