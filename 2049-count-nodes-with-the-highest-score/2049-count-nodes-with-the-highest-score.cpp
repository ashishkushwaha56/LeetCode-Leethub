class Solution {
public:
    map<long long,int> mb;
    long long dfs(vector<vector<int>>&v,int i,vector<int> &vis, int &n){
        if(i>=n){
            return 0;
        }
        long long res1 = 0;
        long long res2 = 0;
        vis[i] = 1;
        if(v[i].size() == 3){
            if(!vis[v[i][0]]){
                if(res1 == 0){
                    res1 = dfs(v,v[i][0],vis,n);
                }
                else{
                    res2 = dfs(v,v[i][0],vis,n);
                }
            }
            if(!vis[v[i][1]]){
                if(res1 == 0){
                    res1 = dfs(v,v[i][1],vis,n);
                }
                else{
                    res2 = dfs(v,v[i][1],vis,n);
                }
            }
            if(!vis[v[i][2]]){
                if(res1 == 0){
                    res1 = dfs(v,v[i][2],vis,n);
                }
                else{
                    res2 = dfs(v,v[i][2],vis,n);
                }
            }
        }
        else if(v[i].size() == 2){
            if(!vis[v[i][0]]){
                if(res1 == 0){
                    res1 = dfs(v,v[i][0],vis,n);
                }
                else{
                    res2 = dfs(v,v[i][0],vis,n);
                }
            }
            if(!vis[v[i][1]]){
                if(res1 == 0){
                    res1 = dfs(v,v[i][1],vis,n);
                }
                else{
                    res2 = dfs(v,v[i][1],vis,n);
                }
            }
        }
        else{
            if(!vis[v[i][0]]){
                res1 = dfs(v,v[i][0],vis,n);
            }
        }
        if(res1>0 and res2>0){
            if(i == 0){
                // cout<<res1<<" "<<res2<<endl;
                mb[(long long)res1*res2]++;
            }
            else
                mb[(long long)(n-1-res1-res2)*res1*res2]++;
        }
        else{
            if(res1>0){
                if(i == 0)
                    mb[res1]++;
                else
                    mb[(long long)(n-1-res1)*res1]++;
                
            }
            else if(res2>0){
                if(i == 0){
                    mb[res2]++;
                }
                else
                    mb[(long long)(n-1-res2)*res2]++;
            }
            else{
                mb[(n-1)]++;
            }
        }
        return (1+res1+res2);
    }
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
       vector<vector<int>> v(n);
        for(int i = 1;i<n;i++){
            v[parents[i]].push_back(i);
            v[i].push_back(parents[i]);
        }
        vector<int> vis(n);
        long long t = dfs(v,0,vis,n);
        auto it = mb.end();
        it--;
        return (*it).second;
    }
};