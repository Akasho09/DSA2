class Solution {
public:
    int preIndex = 0;
    unordered_map<int, int> inorderIndex;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++) inorderIndex[inorder[i]]=i;
        return build(preorder, 0, inorder.size() - 1);
    }
    
    TreeNode* build(vector<int>& preorder, int inStart, int inEnd) {
        if(inStart>inEnd) return nullptr;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int index = inorderIndex[rootVal];

        root->left = build(preorder, inStart, index - 1);
        root->right = build(preorder, index+1 , inEnd);

        return root;
    }
};
