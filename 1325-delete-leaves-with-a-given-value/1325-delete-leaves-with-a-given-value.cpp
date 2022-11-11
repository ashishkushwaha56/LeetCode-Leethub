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
    bool dfs(TreeNode *root,int &t){
        if(root==NULL){
            return true;
        }
        bool a1 = dfs(root->left,t);
        if(a1) {
            root->left = NULL;
        }
        bool a2 = dfs(root->right,t);
        if(a2){
            root->right = NULL;
        }
        return (a1 and a2 and (root->val == t));
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        bool ok = dfs(root,target);
        if(ok){
            root = NULL;
        }
        return root;
    }
};