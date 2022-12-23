class Solution {
public:
    
    
    int ans = 0;
    
    void bfs(int i,vector<vector<int>> &adj,vector<int>&vis){
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        int t;
        while(!q.empty()){
            t = abs(q.front());
            q.pop();
            for(auto &it:adj[t]){
                if(!vis[abs(it)]){
                    vis[abs(it)] = 1;
                    if(it>0) ++ans;
                    q.push(it);
                }
            }
        }
        
    }
    void dfs(int &i,vector<vector<int>> &adj,vector<vector<int>> &temp,vector<int>&vis){
        vis[i] = 1;
        for(auto &it:adj[i]){
            if(!vis[it]){
                if(temp[i][it]) ++ans;
                dfs(it,adj,temp,vis);
            }
        }
        
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(connections.size()+1);
        // vector<vector<int>> temp(connections.size()+1,vector<int>(connections.size()+1));
        for(int i = 0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(-connections[i][0]);
            // temp[connections[i][0]][connections[i][1]] = 1;
        }
        vector<int> vis(adj.size());
        int i = 0;
        bfs(i,adj,vis);
        return ans;
    }
};