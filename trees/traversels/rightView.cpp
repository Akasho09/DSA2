class Solution {
public:
    void helper(TreeNode* root , vector<int>&ans , int i) {
        if(!root) return;

        if(ans.size()==i) ans.push_back(root->val);
        if(root->right) { helper(root->right , ans , i+1);}
        if(root->left ) { helper(root->left , ans , i+1);} 

        return ;
    }
    vector<int> rightSideView(TreeNode* root) {
         vector<int>ans; 
        if(!root) return {};
        helper(root , ans , 0 );
        return ans ;
    }
};