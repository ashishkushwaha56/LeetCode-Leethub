/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    set<int> mb;
    vector<TreeNode*> ans;
    TreeNode* dfs(TreeNode*root){
        if(!root) return NULL;
        TreeNode* left_ = dfs(root->left);
        TreeNode* right_ = dfs(root->right);
        if(mb.find(root->val)!=mb.end()){
            mb.erase(root->val);
            if(left_) ans.push_back(left_);
            if(right_) ans.push_back(right_);
            return NULL;
        }
        if(!left_) root->left= NULL;
        if(!right_) root->right = NULL;
        return root;      
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto &it:to_delete){
            mb.insert(it);
        }
        TreeNode * d = dfs(root);
        if(d) ans.push_back(d);
        return ans;
    }
};