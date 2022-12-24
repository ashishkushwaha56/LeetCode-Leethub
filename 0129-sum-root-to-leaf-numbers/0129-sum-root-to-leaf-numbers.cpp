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
    int res = 0;
    void dfs(TreeNode* root,string &ans){
        if(root == NULL){
            
            return;
        }
        
        ans+=(root->val+'0');
        if(!root->left and !root->right) res+=stoi(ans);
        dfs(root->left,ans);
        dfs(root->right,ans);
        ans.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        string ans = "";
        dfs(root,ans);
        return res;
    }
};