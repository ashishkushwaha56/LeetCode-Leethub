class Solution {
public:
    void dfs(vector<set<int>>&v,vector<int>&vis,int i,int &cnt){
        vis[i] = 1;
        cnt++;
        // cout<<i<<" ";
        for(auto &it:v[i]){
            if(!vis[it]){
                dfs(v,vis,it,cnt);
            }
        }
        // vis[i] = 0;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        vector<set<int>> v(bombs.size()+1);
        for(int i = 0;i<bombs.size();i++){
            for(int j = 0;j<bombs.size();j++){
                if(i == j) continue; 
                if(v[i].find(j)!=v[i].end()) continue;
                long long a = bombs[i][0]-bombs[j][0];
                long long b = bombs[i][1]-bombs[j][1];
                int diff = ceil(sqrt(a*a+b*b));
                // cout<<diff<<" "<<bombs[i][2]<<endl;
                // cout<<i<<" "<<j<<endl;
                if(bombs[i][2]>=diff){
                    v[i].insert(j);
                    // v[j].insert(i);
                }
            }
        }
        vector<int> vis(bombs.size()+1);
        int maxd = 0;
        int cnt= 0;
        // for(auto &it:v){
        //     for(auto &i:it){
        //         cout<<i<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i = 0;i<vis.size();i++){
            cnt = 0;
            for(int j = 0;j<vis.size();j++){
                vis[j] = 0;
            }
            if(!vis[i]){
                
                // if(i == 3){
                    // cout<<i<<" "<<cnt<<endl;
                    dfs(v,vis,i,cnt);
                    // cout<<i<<" "<<cnt<<endl;
                // }
                    
                maxd = max(maxd,cnt);
            }
        }
        return maxd;
    }
};