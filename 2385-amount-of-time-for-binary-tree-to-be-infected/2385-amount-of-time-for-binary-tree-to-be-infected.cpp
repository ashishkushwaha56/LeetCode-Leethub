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
    
    void bfs2(TreeNode *root,vector<vector<int>>&adj){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode * t;
        while(!q.empty()){
            t = q.front();
            q.pop();
            if(t->left){
                adj[t->val].push_back(t->left->val);
                adj[(t->left)->val].push_back(t->val);
                q.push(t->left);
                
            }
            if(t->right){
                adj[t->val].push_back(t->right->val);
                adj[t->right->val].push_back(t->val);
                q.push(t->right);
                
            }
        }
    }
    int bfs1(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* t;
        int ans = root->val;
        while(!q.empty()){
            t = q.front();
            q.pop();
            ans = max(ans,t->val);
            if(t->left){
                q.push(t->left);
            }
            if(t->right){
                q.push(t->right);
            }
        }
        return ans;
    }
    
    int bfs(vector<vector<int>>&adj,int start,vector<int> &vis){
        int ans = 0;
        queue<int> q;
        q.push(start);
        int temp;
        int t = 1;
        int c = 0;
        vis[start] = 1;
        while(!q.empty()){
            temp = q.front();
            q.pop();
            t--;
            for(auto &it:adj[temp]){
                if(!vis[it]){
                    vis[it] = 1;
                    c++;
                    q.push(it);
                }
            }
            if(t == 0){
                ans++;
                t = c;
                c = 0;
            }
        }
        return ans-1;
    }
    int amountOfTime(TreeNode* root, int start) {
        int n = bfs1(root);
        // cout<<n<<endl;
        vector<vector<int>> adj(n+1);
        bfs2(root,adj);
        // for(int i = 0;i<adj.size();i++){
        //     for(int j = 0;j<adj[i].size();j++){
        //         cout<<adj[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<int> vis(n+1);
        int res = bfs(adj,start,vis);
        // cout<<res<<endl;
        return res;
    }
};