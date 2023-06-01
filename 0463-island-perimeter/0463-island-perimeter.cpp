class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        int d = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    ans+=4;
                    if(i-1>=0){
                    if(grid[i-1][j]==1) d++;
                }
                if(j-1>=0){
                    if(grid[i][j-1]==1) d++;
                }
                if(i+1<grid.size()){
                    if(grid[i+1][j]==1) d++;
                }
                if(j+1<grid[0].size()){
                    if(grid[i][j+1]==1) d++;
                }
                }
                
                // cout<<i<<j<<endl;
                // cout<<d<<endl;
                // if(i+1<grid.size() and grid[i+1][j] == 1) d++;
                // if(j+1<grid[0].size() and grid[i][j+1] == 1) d++;
            }
        }
        // cout<<d<<endl;
        return (ans-(d));
    }
};