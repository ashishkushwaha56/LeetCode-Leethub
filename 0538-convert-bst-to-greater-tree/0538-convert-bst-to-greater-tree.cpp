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
    void dfs(TreeNode*root,int &right_sum){
        if(!root) return ;
        
        dfs(root->right,right_sum);
        right_sum+=root->val;
        root->val = right_sum;
        
        dfs(root->left,right_sum);
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        dfs(root,sum);
        return root;
    }
};