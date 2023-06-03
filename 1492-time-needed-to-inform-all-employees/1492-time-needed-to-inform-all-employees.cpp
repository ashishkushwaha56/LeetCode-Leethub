class Solution {
public:
    int ans = 0;
    // void bfs(vector<vector<int>>&v,vector<int>&vis,vector<int>&informTime,int headID){
    //     // vector<int>tt;
    //     queue<int>q;
    //     int temp;
    //     q.push(headID);
    //     // int t = 1;
    //     // int c =0;
    //     vis[headID] = 1;
    //     while(!q.empty()){
    //         temp = q.front();
    //         q.pop();
    //         // t--;
    //         if(v[temp].size()>0)
    //             ans+=informTime[temp];

    //         for(auto&it:v[temp]){
    //             if(!vis[it]){
    //                 q.push(it);
    //                 // c++;
    //                 vis[it] = 1;
    //             }
    //         }
    //     }
    // }
    void dfs(vector<vector<int>>&v,vector<int>&vis,int i,vector<int>&informTime,int cnt){
        vis[i] = 1;
        ans= max(ans,cnt);
        for(auto &it:v[i]){
            if(!vis[it]){
                dfs(v,vis,it,informTime,cnt+informTime[i]);
            }
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>v(manager.size());
        for(int i = 0;i<manager.size();i++){
            if(i == headID) continue;
            v[i].push_back(manager[i]);
            v[manager[i]].push_back(i);
        }
        vector<int> vis(manager.size());
        dfs(v,vis,headID,informTime,0);
        return ans;
    }
};