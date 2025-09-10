class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        TreeNode* rooty = root;
        TreeNode* parent = root;
        while(rooty){
            parent = rooty;
            if(rooty->val < val) {
                rooty = rooty->right;
            } else rooty = rooty->left;
        }

        TreeNode* node = new TreeNode(val);
        if(parent->val < val ){
            parent->right = node ;
        } else parent->left = node;

        return root;
    }
};
