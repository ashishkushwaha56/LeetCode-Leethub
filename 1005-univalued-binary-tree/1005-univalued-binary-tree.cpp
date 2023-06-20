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
    bool ok = true;
    int dfs(TreeNode*root){
        if(!root->left and !root->right) return root->val;
        int a = root->val,b = root->val;
        if(root->left){
            a = dfs(root->left);
        }
        if(root->right){
            b = dfs(root->right);
        }
        if(a !=root->val or b!=root->val) ok = false;
        return root->val;
    }
    bool isUnivalTree(TreeNode* root) {
        dfs(root);
        return ok;
    }
};