class Solution {
public:
    int a = 0;
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};
    void dfs(vector<vector<int>> &v,int i, int j){
        if(i<0 or i>=v.size() or j<0 or j>=v[0].size()) return;
        if(v[i][j] == 0) return;
        v[i][j] = 0;
        a++;
        for(int k = 0;k<4;k++){
            dfs(v,i+dx[k],j+dy[k]);
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]){
                    a=0;
                    dfs(grid,i,j);
                    ans = max(ans,a);
                }
            }
        }
        return ans;
    }
};