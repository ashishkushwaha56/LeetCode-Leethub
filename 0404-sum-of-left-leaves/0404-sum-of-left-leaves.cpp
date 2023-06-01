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
    void dfs(TreeNode* root,int flag,int &ans){
        if(!root) return;
        if(!root->left and !root->right and flag == 0){
            ans+=root->val;
        }
        dfs(root->left,0,ans);
        dfs(root->right,1,ans);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        dfs(root,-1,ans);
        return ans;
    }
};