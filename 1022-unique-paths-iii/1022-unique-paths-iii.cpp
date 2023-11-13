class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int nonobs = 0;
        
        int cnt = 0;
        int ans = 0;
        int n = grid.size(),m = grid[0].size();
        int start_i = 0,start_j = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] !=-1) nonobs++;
                if(grid[i][j] == 1){
                    start_i = i,start_j = j;
                }
            }
        }
        vector<int> dx = {0,0,-1,1};
        vector<int> dy = {1,-1,0,0};
        function<void(int, int,int)> dfs = [&](int i, int j,int temp){
            if(i>=n or j>= m or i<0 or j<0) return ;
            if(grid[i][j] == 1 or grid[i][j] == -1) return ;
            if(grid[i][j] == 2){
                if(temp==nonobs-2) ans++;
                return; 
            }
            grid[i][j] = 1;
            for(int k = 0;k<4;k++){
                dfs(i+dx[k],j+dy[k],temp+1);
            }
            grid[i][j] = 0;
        };
        for(int k = 0;k<4;k++){
            dfs(start_i+dx[k],start_j+dy[k],0);
        }
        return ans;
    }
};