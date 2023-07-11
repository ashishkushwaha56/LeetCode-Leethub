/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> adj;
    void dfs(TreeNode* root){
        if(root->left){
            adj[root->val][root->left->val] = 1;
            adj[root->left->val][root->val] = 1;
            dfs(root->left);
        }
        if(root->right){
            adj[root->val][root->right->val] = 1;
            adj[root->right->val][root->val] = 1;
            dfs(root->right);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        adj.resize(501,vector<int>(501,0));
        dfs(root);
        vector<int> vis(501,0);
        queue<int> q;
        q.push(target->val);
        int t = 1;
        int c = 0;
        vector<int> temp;
        int cnt = 0;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            t--;
            vis[x] = 1;
            temp.push_back(x);
            for(int i = 0;i<501;i++){
                if(i ==x) continue;
                if(adj[x][i]==1 and vis[i]==0){
                    q.push(i);
                    c++;
                }
            }
            if(t==0){
                t = c;
                c = 0;
                if(cnt == k) return temp;
                cnt++;
                temp.clear();
            }
        }
        return temp;
    }
};