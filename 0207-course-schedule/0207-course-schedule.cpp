class Solution {
public:
    bool ok = false;
    void dfs(vector<vector<int>>&adj,vector<int>&vis,vector<int>&d,int i){
        if(ok) return;
        vis[i] = 1;
        d[i]=1;
        for(auto &it:adj[i]){
            if(vis[it] and d[it] == 1){
                ok = true;
            }
            if(!vis[it]){
                dfs(adj,vis,d,it);
            }
        }
        d[i] = 0;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>>adj(n);
        for(auto &it:pre){
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n),d(n);
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                dfs(adj,vis,d,i);
            }
        }
        if(ok) return false;
        return true;
    }
};