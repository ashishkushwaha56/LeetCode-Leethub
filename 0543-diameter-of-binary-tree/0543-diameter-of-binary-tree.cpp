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
    int ans = 0;
    // Function to return the diameter of a Binary Tree.
    int dfs(TreeNode *root){
    	if(!root) return 0;
    	int a = dfs(root->left);
    	int b = dfs(root->right);
    	ans = max(a+b,ans);
    	return 1+max(a,b);
    }
    int diameterOfBinaryTree(TreeNode* root) {
       int a =dfs(root->left);
    	int b = dfs(root->right);
    	ans = max(a+b,ans);
        return ans;
        
    }
};