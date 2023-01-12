class Solution {
public:
    
    vector<int> dfs(vector<vector<int>>&adj,vector<int> &vis,int i,string &labels,vector<int>&ans){
        vector<int> a(26),b(26);
        vis[i] = 1;
        a[labels[i]-'a']++;
        for(auto &it:adj[i]){
            if(!vis[it]){
                b = dfs(adj,vis,it,labels,ans);
                for(int j = 0;j<26;j++){
                    a[j]+=b[j];
                    b[j] = 0;
                }
                
            }
        }
        ans[i] = a[labels[i]-'a'];
        return a;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for(int i = 0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> ans(n);
        vector<int> vis(n,0);
        vector<int> res = dfs(adj,vis,0,labels,ans);
        return ans;
        
    }
};