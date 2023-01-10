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
    vector<int> a,b;
    void dfs(TreeNode*root,bool &temp){
        if(!root){
            if(!temp)
                a.push_back(-1);
            else
                b.push_back(-1);
            return;
        }
        if(!temp)
            a.push_back(root->val);
        else
            b.push_back(root->val);
        dfs(root->left,temp);
        dfs(root->right,temp);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool temp = 0;
        dfs(p,temp);
        temp = 1;
        dfs(q,temp);
        return a==b;
    }
};