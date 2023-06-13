class Solution {
public:
    int vis[54][54];
    vector<int>dx = {0,0,1,-1};
    vector<int>dy = {1,-1,0,0};
    int bfs(pair<int,int>&start,pair<int,int>&end, vector<vector<int>>&grid){
        int ans = 0;
        queue<pair<int,int>>q;
        q.push({start.first,start.second});
        pair<int,int>temp;
        int t =1;
        int c = 0;
        vis[start.first][start.second] = 1;
        while(!q.empty()){
            temp = q.front();
            q.pop();
            // if(vis[temp.first][temp.second]) continue;
            // vis[temp.first][temp.second] = 1;
            t--;
            // cout<<temp.first<<" "<<temp.second<<" "<<ans<<" "<<t<<endl;
            if(temp.first == end.first and temp.second == end.second) return ans;
            for(int i = 0;i<4;i++){
                if(temp.first+dx[i]>=0 and temp.first+dx[i]<grid.size() and temp.second+dy[i]>=0 and temp.second+dy[i]<grid[0].size() and grid[temp.first+dx[i]][temp.second+dy[i]]>0 and !vis[temp.first+dx[i]][temp.second+dy[i]]){
                    c++;
                    vis[temp.first+dx[i]][temp.second+dy[i]] = 1;
                    q.push({temp.first+dx[i],temp.second+dy[i]});
                }
            }
            if(t == 0){
                t =c;
                c = 0;
                ans++;
            }
        }
        return -1;
    }
    int cutOffTree(vector<vector<int>>& grid) {
        vector<pair<int,pair<int,int>>> v;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]>1){
                    v.push_back({grid[i][j],{i,j}});
                }
            }
        }
        v.push_back({0,{0,0}});
        sort(v.begin(),v.end());
        int ans= 0;
        for(int i = 0;i<v.size()-1;i++){
            for(int j = 0;j<54;j++){
                for(int k = 0;k<54;k++){
                    vis[j][k] = 0;
                }
            }
            pair<int,int> start = {v[i].second.first,v[i].second.second};
            pair<int,int> end = {v[i+1].second.first,v[i+1].second.second};
            // cout<<v[i].first<<" "<<v[i+1].first<<endl;
            int a = bfs(start,end,grid);
            // cout<<a<<endl;
            if(a == -1) return -1;
            ans+=a;

        }
        return ans;
    }
};