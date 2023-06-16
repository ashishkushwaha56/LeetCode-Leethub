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
    int ans =INT_MIN;
    int dfs(TreeNode*root){
        if(!root) return 0;
        int a = max(dfs(root->left),0);
        int b = max(dfs(root->right),0);
        ans = max(ans,root->val+a+b);
        return root->val+max(a,b);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};