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
    vector<int> findMode(TreeNode* root) {
        map<int,int> mb;
        function<void(TreeNode*)> dfs = [&](TreeNode* root)->void{
            if(!root) return;
            mb[root->val]++;
            dfs(root->left);
            dfs(root->right);
        };
        dfs(root);
        int cnt = 0;
        for(auto &it:mb){
            cnt = max(it.second,cnt);
        }
        vector<int> ans;
        for(auto &it:mb){
            if(it.second == cnt) ans.push_back(it.first);
        }
        return ans;
    }
};