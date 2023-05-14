class Solution {
public:
    
    vector<int> dx = {0,0,1,-1};
    vector<int> dy = {1,-1,0,0};
   int dfs(vector<vector<int>>&v,int i,int j){
        if(i<0 or i>=v.size() or j<0 or j>=v[0].size()) return 0;
        if(v[i][j] == 0) return 0;
        
        int cnt = v[i][j];
       v[i][j] = 0;
        for(int k = 0;k<4;k++){
            cnt+=dfs(v,i+dx[k],j+dy[k]);
        }
        
        return (cnt);
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[i].size();j++){
                if(grid[i][j]>0)
                    ans = max(ans,dfs(grid,i,j));
            }
        }
        return ans;
    }
};