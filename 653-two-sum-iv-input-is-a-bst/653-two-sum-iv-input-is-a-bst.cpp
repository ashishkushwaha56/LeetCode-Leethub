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
    // bool ok = false;
    unordered_map<int,int> mb;
    bool dfs(TreeNode*root,int &k){
        if(!root) return false;
        if(mb.find(k-root->val)!=mb.end()) return true;
        mb[root->val]++;
        return (dfs(root->left,k) or dfs(root->right,k));
    }
    bool findTarget(TreeNode* root, int &k) {
        return dfs(root,k);
    }
};