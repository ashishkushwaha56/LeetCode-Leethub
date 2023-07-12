class Solution {
public:
    unordered_map<int,bool> mb;
    bool check(vector<vector<int>>&adj,int i, vector<int>&vis){
        if(vis[i] == 1 and mb.find(i)==mb.end()){
            return false;
        }
        if(vis[i] == 1 and mb[i] == false){
            return false;
        }
        if(vis[i] == 1 and mb[i] == true) return true;
        vis[i] = 1;
        bool ans = true;
        for(auto &it:adj[i]){
            ans&=check(adj,it,vis);
        }
        return mb[i] = ans;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>vis(graph.size());
        for(int i = 0;i<graph.size();i++){
            if(!vis[i]){
                check(graph,i,vis);
            }
        }
        vector<int> ans;
        for(auto &it:mb){
            if(it.second ==true) ans.push_back(it.first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};