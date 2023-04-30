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
    void dfs(TreeNode* root){
        if(!root){return;}
        dfs(root->left);
        v.push_back(root->val);
        dfs(root->right);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans(queries.size(),vector<int>(2));
        dfs(root);
        for(int i = 0;i<queries.size();i++){
            auto it = lower_bound(v.begin(),v.end(),queries[i]);
            if(it == v.end()){
                ans[i][1] = -1;
                it--;
                ans[i][0] = *it;
            }
            else{
                if(*it == queries[i]){
                    ans[i][0] = ans[i][1] = queries[i];
}
                else{
                    
                    ans[i][1] = *it;
                    if(it != v.begin()){
                        it--;
                    ans[i][0] = *it;
                    }
                    else ans[i][0] = -1;
                    
                }
            }
        }
        return ans;
    }
};