class Solution {
public:
    int dfs(vector<vector<int>> &v,int i,vector<int>&vis){
        vis[i] = 1;
        int ans = 0;
        for(auto &it:v[i]){
            if(!vis[it]){
                ans+=dfs(v,it,vis);
            }
        }
        return 1+ans;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> v(n);
        for(int i = 0;i<edges.size();i++){
            v[edges[i][0]].push_back(edges[i][1]);
            v[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>vis(n,false);
        for(auto &it:restricted){
            vis[it] = 1;
        }
        int ans = dfs(v,0,vis);
        return ans;
    }
};