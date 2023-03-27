class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> ans(grid.size(),vector<int>(grid[0].size()));
        int x= 1e9,y = 1e9;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(i == 0 and j == 0) ans[i][j] = grid[i][j];
                else{
                    x = 1e9,y = 1e9;
                    if(i>0)
                        x = ans[i-1][j];
                    
                    if(j>0)
                        y = ans[i][j-1];
                    ans[i][j] = grid[i][j]+min(x,y);
                }
            }
        
        }
        return ans[grid.size()-1][grid[0].size()-1];
    }
};