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
    map<vector<int>,TreeNode*> ans;
    map<vector<int>,int> mb;
    vector<int> dfs(TreeNode*root){
        if(!root){
            return {-201};
        }
        vector<int> l = dfs(root->left);
        vector<int> r = dfs(root->right);
        for(auto &it:r){
            l.push_back(it);
        }
        l.push_back(root->val);
        if(mb.find(l)!=mb.end() and ans.find(l)==ans.end()){
            ans[l] = root;
        }
        else{
            mb[l]++;
        }
        return l;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<int> a = dfs(root);
        vector<TreeNode*> res;
        for(auto &it:ans){
            res.push_back(it.second);
        }
        return res;
    }
};