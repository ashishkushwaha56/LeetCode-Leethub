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
        
        if(!root) return 0;
        int a = dfs(root->left);
        int b = dfs(root->right);
        if(abs(a-b)>1) ok = false;
        return 1+max(a,b);

    }
    bool isBalanced(TreeNode* root) {
        int a = dfs(root);
        return ok;
    }
};