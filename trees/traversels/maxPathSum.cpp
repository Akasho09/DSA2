#include <iostream>
using namespace std;

int main (){



}


class Solution {
public:
    int helper(TreeNode* root , int &ans ){
        if(!root) return 0 ;

        int l = max (0 , helper(root->left , ans ));
        int r = max (0 , helper(root->right , ans));
        ans = max(ans , l+r+root->val) ;

        return root->val + max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN ;
        helper(root , ans );
        return ans ;
    }
};