class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<vector<int>> &adj,vector<int>&vis,int i,vector<int>&temp){
        
        vis[i] = 1;
        temp.push_back(i);
        if(i == adj.size()-1){
            ans.push_back(temp);
        }
        for(auto &it:adj[i]){
            if(!vis[it]){
                dfs(adj,vis,it,temp);
            }
        }
        temp.pop_back();
        vis[i] = 0;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> vis(graph.size());
        vector<int> temp;
        dfs(graph,vis,0,temp);
        return ans;
    }
};