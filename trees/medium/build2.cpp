class Solution {
public:
    int postInd ;
    unordered_map<int , int > inorderIndex ;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size(); postInd = n-1;
        for(int i=0;i<n;i++) inorderIndex[inorder[i]]=i;

        return build (postorder , 0 , n-1);
    }

    TreeNode* build(vector<int>& postorder , int inSt , int inEnd ){
        if(inSt>inEnd) return nullptr ;

        int rootval = postorder[postInd--];
        TreeNode* root = new TreeNode(rootval);

        int ind = inorderIndex[rootval];

        root->right = build (postorder , ind+1 , inEnd );
        root->left = build (postorder , inSt , ind-1 );

        return root;
    }
};
