class Solution {
public:
    vector<int> dx = {1,-1,0,0};
    vector<int> dy={0,0,-1,1};
    bool bfs(vector<vector<int>>&heights,vector<vector<int>>&vis,int mid){
        queue<pair<int,int>> q;
        pair<int,int> temp;
        vis[0][0] = 1;
        q.push({0,0});
        while(!q.empty()){
            temp = q.front();
            q.pop();
            if(temp.first == heights.size()-1 and temp.second == heights[0].size()-1) return true;
            for(int i=0;i<4;i++){
                if(temp.first+dx[i]>=0 and temp.first+dx[i]<heights.size() and temp.second+dy[i]>=0 and temp.second+dy[i]<heights[0].size()){
                    if(!vis[temp.first+dx[i]][temp.second+dy[i]] and abs(heights[temp.first][temp.second]-heights[temp.first+dx[i]][temp.second+dy[i]])<=mid){
                        vis[temp.first+dx[i]][temp.second+dy[i]] =1;
                        q.push({temp.first+dx[i],temp.second+dy[i]});
                    }
                }
            }
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int l =0;
        int r = INT_MAX;
        int ans = r;
        vector<vector<int>> vis(heights.size(),vector<int>(heights[0].size()));
        while(l<=r){
            int mid = l+(r-l)/2;
            for(int i = 0;i<vis.size();i++){
                for(int j = 0;j<vis[0].size();j++){
                    vis[i][j]= 0;
                }
            }
            if(bfs(heights,vis,mid)) {
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};