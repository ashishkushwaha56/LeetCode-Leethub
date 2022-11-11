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
    pair<int,int> dfs(TreeNode* root){
        if(root ==NULL){
            return {0,0};
        }
        pair<int,int> p1 = dfs(root->left);
        pair<int,int> p2 = dfs(root->right);
        if(root->val == (p1.first+p2.first+root->val)/(p1.second+p2.second+1)){
            ans++;
        }
        return {p1.first+p2.first+root->val,p1.second+p2.second+1};
    }
    int averageOfSubtree(TreeNode* root) {
        pair<int,int> p = dfs(root);
        return ans;
    }
};