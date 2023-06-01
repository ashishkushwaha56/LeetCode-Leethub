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
    vector<string> ans;
    void dfs(TreeNode* root,string s){
        if(!root)return;
        s+=to_string(root->val);
        s+='-';
        s+='>';
        if(!root->left and !root->right){
            s.pop_back();
            s.pop_back();
            ans.push_back(s);
            
        }
        dfs(root->left,s);
        dfs(root->right,s);
       
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s = "";
        dfs(root,s);
        return ans;
    }
};