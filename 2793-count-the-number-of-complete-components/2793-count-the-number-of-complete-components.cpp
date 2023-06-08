class Solution {
public:
    void dfs(vector<vector<int>>&adj,vector<int>&vis,int &cnt,int &node,int i){
        node++;
        vis[i] = 1;
        cnt+=(adj[i].size());
        for(auto &it:adj[i]){
            if(!vis[it]){
                dfs(adj,vis,cnt,node,it);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n);
        int cnt = 0;
        int node = 0;
        int a;
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                cnt = 0;
                node = 0;

                dfs(adj,vis,cnt,node,i);
                // cout<<node<<" "<<cnt<<endl;
                a = (node*(node-1))/2;
                if(cnt == a*2) ans++;
            }
        }
        return ans;
    }
};