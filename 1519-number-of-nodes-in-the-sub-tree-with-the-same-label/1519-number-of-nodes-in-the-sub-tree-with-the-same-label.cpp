class Solution {
public:
    
    unordered_map<char,int> dfs(vector<vector<int>>&adj,vector<int> &vis,int i,string &labels,vector<int>&ans){
        unordered_map<char,int> a,b;
        vis[i] = 1;
        a[labels[i]]++;
        for(auto &it:adj[i]){
            if(!vis[it]){
                b = dfs(adj,vis,it,labels,ans);
                for(auto &c:b){
                    a[c.first]+=c.second;
                }
                b.clear();
            }
        }
        ans[i] = a[labels[i]];
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
        unordered_map<char,int> res = dfs(adj,vis,0,labels,ans);
        return ans;
        
    }
};