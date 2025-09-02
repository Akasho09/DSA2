#include <iostream>
using namespace std;

int main (){



}
class Solution {
public:
    bool helper(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val != q->val) return false;

        return helper(p->left , q->left) && helper(p->right , q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return helper(p , q);
    }
};