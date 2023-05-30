class Solution {
public:

    void dfs(vector<vector<int>>&adj,vector<int> &vis,vector<int>&temp,int i){
        vis[i] = 1;
        for(int j = 0;j<adj[i].size();j++){
            if(adj[i][j] == 1 and !vis[j]){
                temp.push_back(j);
                dfs(adj,vis,temp,j);
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string,set<int>> mb;
        for(int i = 0;i<accounts.size();i++){
            for(int j = 1;j<accounts[i].size();j++){
                mb[accounts[i][j]].insert(i); 
            }
        }
        vector<vector<int>> adj(accounts.size(),vector<int>(accounts.size()));
        for(int i = 0;i<accounts.size();i++){
            for(int j = 1;j<accounts[i].size();j++){
                mb[accounts[i][j]].erase(i);
                for(auto &it:mb[accounts[i][j]]){
                    adj[i][it] = 1;
                    adj[it][i] = 1;
                }
            }
        }
        // for(int i = 0;i<adj.size();i++){
        //     for(int j = 0;j<adj.size();j++){
        //         cout<<adj[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<int> vis(accounts.size());
        vector<int> temp;
        vector<vector<string>> ans;
        vector<string> v;
        set<string> sd;
        for(int i = 0;i<accounts.size();i++){
            if(!vis[i]){
                dfs(adj,vis,temp,i);
                v.clear();
                sd.clear();
                for(int j = 1;j<accounts[i].size();j++){
                    sd.insert(accounts[i][j]);
                }
                for(auto &it:temp){
                    for(int j = 1;j<accounts[it].size();j++){
                        sd.insert(accounts[it][j]);
                    }
                }
                v.push_back(accounts[i][0]);
                for(auto &it:sd){
                    v.push_back(it);
                }
                ans.push_back(v);
                temp.clear();
            }
            else{
                v.clear();
                sd.clear();
                for(int j = 1;j<accounts[i].size();j++){
                    sd.insert(accounts[i][j]);
                }
            }
            // for(auto &it:temp){
            //     cout<<it<<" ";
            // }
            // cout<<endl;
            // v.clear();
            // sd.clear();
            // for(int j = 1;j<accounts[i].size();j++){
            //     sd.insert(accounts[i][j]);
            // }
            // for(auto &it:temp){
            //     for(int j = 1;j<accounts[it].size();j++){
            //         sd.insert(accounts[it][j]);
            //     }
            // }
            // v.push_back(accounts[i][0]);
            // for(auto &it:sd){
            //     v.push_back(it);
            // }
            // ans.push_back(v);
            // temp.clear();
        }
        return ans;
    }
};