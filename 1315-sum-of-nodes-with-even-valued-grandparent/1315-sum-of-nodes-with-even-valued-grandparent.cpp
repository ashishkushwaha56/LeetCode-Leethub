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
    void dfs(TreeNode* root){
        if(root == NULL){
            return;
        }
        if(!(root->val&1) and root->left!=NULL){
            if(root->left->left!=NULL){
                ans+=root->left->left->val;
            }
            if(root->left->right!=NULL){
                ans+=root->left->right->val;
            }
        }
        if(!(root->val&1) and root->right!=NULL){
            if(root->right->left!=NULL){
                ans+=root->right->left->val;
            }
            if(root->right->right!=NULL){
                ans+=root->right->right->val;
            }
        }
        dfs(root->left);
        dfs(root->right);
    }
    int sumEvenGrandparent(TreeNode* root) {
        dfs(root);
        return ans;
    }
};