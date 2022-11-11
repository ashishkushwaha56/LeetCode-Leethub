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
    map<int,int> mb;
    int dfs(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int a1 = dfs(root->left);
        int a2 = dfs(root->right);
        mb[a1+a2+root->val]++;
        return a1+a2+root->val;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        // int d = dfs(root)
        dfs(root);
        vector<pair<int,int>> v;
        for(auto &it:mb){
            v.push_back(it);
        }
        sort(v.begin(),v.end(),[&](pair<int,int>&a,pair<int,int>&b){
            return a.second>b.second;
        });
        int t = v[0].second;
        vector<int> ans;
        for(int i= 0;i<v.size();i++){
            if(v[i].second == t){
                ans.push_back(v[i].first);
            }
        }
        return ans;
    }
};