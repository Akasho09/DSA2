class Solution {
public:
    unordered_map<TreeNode*,TreeNode*>parent ;
    void helper(TreeNode* root , TreeNode* p){
        parent[root] = p ;
        if(root->left) helper(root->left , root);
        if(root->right) helper(root->right , root);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        helper(root ,  nullptr);

        unordered_set<TreeNode*> visited;
        queue<pair<TreeNode*, int>> q;
        q.push({target, 0});
        visited.insert(target);

            vector<int> res;
        
        while(!q.empty()){
            auto [node, dist] = q.front();
            q.pop() ;

            if(dist==k)res.push_back(node->val);
            else if(dist<k){
                if(node->left && !visited.count(node->left)){
                    visited.insert(node->left);
                    q.push({node->left , dist+1});
                }
                if(node->right && !visited.count(node->right)){
                    visited.insert(node->right);
                    q.push({node->right , dist+1});
                }
                if(parent[node] && !visited.count(parent[node])){
                    visited.insert(parent[node]);
                    q.push({parent[node] , dist+1});
                }
            }
            }
            return res;
        }
};