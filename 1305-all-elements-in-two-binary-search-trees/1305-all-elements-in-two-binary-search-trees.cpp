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
    priority_queue<int,vector<int>,greater<int>> p;
    void dfs1(TreeNode* root1){
        if(root1==NULL){
            return;
        }
        p.push(root1->val);
        dfs1(root1->left);
        dfs1(root1->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        dfs1(root1);
        dfs1(root2);
        while(!p.empty()){
            ans.push_back(p.top());
            p.pop();
        }
        return ans;
    }
};