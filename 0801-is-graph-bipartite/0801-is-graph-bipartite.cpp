class Solution {
public:
    bool ok = true;
    map<int,int> mb;
    void dfs(vector<vector<int>>&graph,vector<int>&vis,int parent,int i,int cnt){
        if(!ok) return;
        vis[i] = 1;
        mb[i] = cnt;
        for(auto &it:graph[i]){
            if(vis[it] and parent!=it){
                if((abs(mb[it]-cnt+1))&1){
                    ok = false;
                }
            }
            if(!ok) return;
            if(!vis[it]){
                dfs(graph,vis,i,it,cnt+1);
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size());
        for(int i = 0;i<graph.size();i++){
            if(!ok) return false;
            if(!vis[i]){
                dfs(graph,vis,-1,i,0);
            }
        }
        return ok;
    }
};