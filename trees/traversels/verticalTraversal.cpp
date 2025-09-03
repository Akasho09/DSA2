#include <iostream>
#include <map>
using namespace std;

int main (){



}


struct TreeNode {
    int val;
 TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    void helper(TreeNode* root , map<pair<int,int> , vector<int>>& mapp , int x , int y){
        if(!root) return ;
        mapp[{x , y}].push_back(root->val);
        if(root->left ) helper(root->left , mapp , x+1 , y-1);
        if(root->right) helper(root->right , mapp , x+1 , y+1);
        return ;
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        map<pair<int,int> , vector<int>>mapp;
        helper(root , mapp , 0  , 0 ); 

        map<int, vector<int>>mapp2;
        for( const auto&a : mapp ) {
            int y = a.first.second ;
            vector<int>temp = a.second ;
            sort(temp.begin() , temp.end());
            for(int i = 0 ; i<temp.size() ; i++){
            mapp2[y].push_back(temp[i]);
            }
        }

        for( const auto&a : mapp2 ) {
            ans.push_back(a.second);
        }

        return ans ;
        
    }
};


class Solution {
public:

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;

        map<pair<int,int> , vector<int>>mapp;
        queue<pair<pair<int,int> , TreeNode*>>q; 
        q.push({ { 0 , 0 } , root});

        while(!q.empty()){
            int s = q.size();
            int prevX = 0 ;
            while(s>0){
                TreeNode* curr = q.front().second;
                int y = q.front().first.second; int x = q.front().first.first;
                mapp[{x,y}].push_back(curr->val);
                s--; q.pop();
                if(curr->left) q.push({ {x+1, y-1 } , curr->left});
                if(curr->right) q.push({ {x+1 , y+1 } , curr->right});
            }
        }

        map<int, vector<int>>mapp2;
        for( const auto&a : mapp ) {
            int y = a.first.second ;
            vector<int>temp = a.second ;
            sort(temp.begin() , temp.end());
            for(int i = 0 ; i<temp.size() ; i++){
            mapp2[y].push_back(temp[i]);
            }
        }

        for( const auto&a : mapp2 ) {
            ans.push_back(a.second);
        }


        return ans ;
        
    }
};


class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;

        map<int , vector<int>>mapp;
        queue<pair<pair<int,int> , TreeNode*>>q; 
        q.push({ { 0 , 0 } , root});

        while(!q.empty()){
            int s = q.size();
            int prevX = 0 ;
            int tx = 0 , ty = 0;
            while(s>0){
                TreeNode* curr = q.front().second;
                int y = q.front().first.second; int x = q.front().first.first;
                if (y == ty && x == tx && !mapp[y].empty() && mapp[y].back() > curr->val) {
                    int temp = mapp[y].back();
                    mapp[y].back() = curr->val;    
                    mapp[y].push_back(temp); 
                } else {
                    mapp[y].push_back(curr->val);
                }
                s--; q.pop();
                tx = x ; ty = y;
                if(curr->left) q.push({ {y-1 , x+1 } , curr->left});
                if(curr->right) q.push({ {y+1 , x+1 } , curr->right});
            }
        }

        for( const auto&a : mapp ) {
            ans.push_back(a.second);
        }

        return ans ;
        
    }
};


class Solution {
public:
    void helper(TreeNode* root , map<int , vector<int>>& mapp , int i){
        if(!root) return ;

        mapp[i].push_back(root->val);
        if(root->left ) helper(root->left , mapp , i-1);
        if(root->right) helper(root->right , mapp , i+1);
        return ;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int , vector<int>>mapp;
        helper(root , mapp , 0);
        vector<vector<int>>ans;

        for( const auto&a : mapp ) {
            ans.push_back(a.second);
        }

        return ans ;
        
    }
};
