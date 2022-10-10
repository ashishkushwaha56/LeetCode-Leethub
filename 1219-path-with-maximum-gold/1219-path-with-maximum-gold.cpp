class Solution {
public:
    vector<int> dx = {0,0,-1,1};
    vector<int> dy = {1,-1,0,0};
    int dfs(vector<vector<int>>&v,int i, int j){
        int res = 0;
        int t = v[i][j];
        v[i][j] = 0;
        
        for(int k = 0;k<4;k++){
            if(i+dx[k]<0 or i+dx[k]>=v.size() or j+dy[k]<0 or j+dy[k]>=v[0].size())
                continue;
            if(!v[i+dx[k]][j+dy[k]]) continue;
            res = max(res,v[i+dx[k]][j+dy[k]]+dfs(v,i+dx[k],j+dy[k]));
        }
        v[i][j] = t;
        return res;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
        int sum = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]){
                   ans = max(ans,grid[i][j]+dfs(grid,i,j));
                }
            }
        }
        return ans;
    }
};