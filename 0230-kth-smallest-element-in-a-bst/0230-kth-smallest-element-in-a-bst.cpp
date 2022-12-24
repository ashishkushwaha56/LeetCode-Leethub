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
    
    void dfs(priority_queue<int>&p,TreeNode * root,int k){
        if(root == NULL) return;
        if(p.size()<k){
            p.push(root->val);
        }
        else{
            if(p.top()>root->val){
                p.pop();
                p.push(root->val);
            }
        }
        dfs(p,root->left,k);
        dfs(p,root->right,k);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> p;
        dfs(p,root,k);
        return p.top();
    }
};