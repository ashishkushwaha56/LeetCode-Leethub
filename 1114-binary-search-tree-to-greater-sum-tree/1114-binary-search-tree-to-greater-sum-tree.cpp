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
    vector<int> v;
    void dfs1(TreeNode*root){
        if(!root) return;
        v.push_back(root->val);
        dfs1(root->left);
        dfs1(root->right);
    }
    void dfs2(TreeNode*root){
        if(!root) return;
        int sum = 0;
        auto it = upper_bound(v.begin(),v.end(),root->val)-v.begin();
        for(int i = it;i<v.size();i++){
            sum+=v[i];
        }
        root->val = sum+root->val;
        dfs2(root->left);
        dfs2(root->right);
    }
    TreeNode* bstToGst(TreeNode* root) {
        dfs1(root);
        sort(v.begin(),v.end());
        // for(auto &it:v){
        //     cout<<it<<' ';
        // }
        // cout<<endl;
        dfs2(root);
        return root;
    }
};