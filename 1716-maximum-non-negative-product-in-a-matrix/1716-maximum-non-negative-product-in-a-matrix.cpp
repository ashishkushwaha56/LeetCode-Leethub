class Solution {
public:
    long long dp_max[20][20];
    long long dp_min[20][20];
    long long helper1(int i,int j,vector<vector<int>>&grid){
        if(i == grid.size()-1 and j == grid[0].size()-1) return grid[i][j];
        if(dp_max[i][j]!=LLONG_MIN) return dp_max[i][j];
        long long ans = LLONG_MIN;
        if(i<grid.size()-1){
            ans = max({ans,grid[i][j]*helper1(i+1,j,grid),grid[i][j]*helper2(i+1,j,grid)});
        }
        if(j<grid[0].size()-1){
            ans = max({ans,grid[i][j]*helper1(i,j+1,grid),grid[i][j]*helper2(i,j+1,grid)});
        }
        return dp_max[i][j] = ans;  
    }
    long long helper2(int i,int j,vector<vector<int>>&grid){
        if(i == grid.size()-1 and j == grid[0].size()-1){
            return grid[i][j];
        }
        if(dp_min[i][j]!=LLONG_MAX) return dp_min[i][j];
        long long ans = LLONG_MAX;
        if(i<grid.size()-1){
            ans = min({ans,grid[i][j]*helper1(i+1,j,grid),grid[i][j]*helper2(i+1,j,grid)});
        }
        if(j<grid[0].size()-1){
            ans = min({ans,grid[i][j]*helper1(i,j+1,grid),grid[i][j]*helper2(i,j+1,grid)});
        }
        return dp_min[i][j] = ans;
    }
    
    int maxProductPath(vector<vector<int>>& grid) {
        int mod = 1e9+7;
        for(int i = 0;i<20;i++){
            for(int j = 0;j<20;j++){
                dp_max[i][j] = LLONG_MIN;
                dp_min[i][j] = LLONG_MAX;
            }
        }
        long long a = helper1(0,0,grid);
        if(a<0) return -1;
        return a%mod;
    }
};