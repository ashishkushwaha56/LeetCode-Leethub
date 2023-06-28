class Solution {
public:
    void bfs(vector<vector<pair<int,double>>>&adj,int start,vector<double>&ans){
        queue<int> q;
        q.push(start);
        int temp;
        while(!q.empty()){
            temp = q.front();
            q.pop();
            // vis[temp.first] = 1;
            for(auto &it:adj[temp]){
                int x = it.first;
                double prob = it.second;
                double d = ans[temp]*prob;
                if(d>ans[x]){
                    ans[x] = d;
                    q.push(x);
                }
            }
        }
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> adj(n);
        // vector<vector<double>> grid(n,vector<double>(n));

        for(int i = 0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
            
        }
        vector<double> ans(n);
        ans[start] = 1;
        // vector<int> vis(n);
        bfs(adj,start,ans);
        return ans[end];
    }
};