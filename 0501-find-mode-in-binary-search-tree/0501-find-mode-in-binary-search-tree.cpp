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
    unordered_map<int,int> mb;
    void dfs(TreeNode* root){
        if(!root) return;
        mb[root->val]++;
        dfs(root->left);
        dfs(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        vector<pair<int,int>> v;
        dfs(root);
        for(auto &it:mb){
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end(),[&](pair<int,int>&a,pair<int,int>&b){
            return a.second>b.second;
        });
        vector<int> ans = {v[0].first};
        for(int i = 1;i<v.size();i++){
            if(v[i].second != v[i-1].second) break;
            ans.push_back(v[i].first);
        }
        return ans;
    }
};