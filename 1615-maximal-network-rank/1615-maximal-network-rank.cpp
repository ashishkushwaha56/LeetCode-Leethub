class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        vector<vector<int>> vis(n,vector<int>(n));
        for(int i = 0;i<roads.size();i++){
            vis[roads[i][0]][roads[i][1]] = 1;                               vis[roads[i][1]][roads[i][0]] = 1;
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        int ans = 0;
        int t = 0;
        for(int i = 0;i<n-1;i++){
            for(int j = i+1;j<n;j++){
                t = 0;
                t+=adj[i].size();
                t+=adj[j].size();
                if(vis[i][j]){
                    t--;
                }
                ans = max(ans,t);
            }
        }
        return ans;
    }
};