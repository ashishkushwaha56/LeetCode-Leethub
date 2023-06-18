class Solution {
public:
    int helper(vector<vector<int>>&dp,int i, int j, int prev,vector<vector<int>>&grid,int &mod){
        if(i<0 or j<0 or i==grid.size() or j==grid[0].size()){
            return 0;
        }
        if(grid[i][j]<=prev) return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up = (helper(dp,i-1,j,grid[i][j],grid,mod))%mod;
        int down = (helper(dp,i+1,j,grid[i][j],grid,mod))%mod;
        int left = (helper(dp,i,j-1,grid[i][j],grid,mod))%mod;
        int right = (helper(dp,i,j+1,grid[i][j],grid,mod))%mod;
        return dp[i][j] = (up+down+left+right+1)%mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        int mod = 1e9+7;
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        int ans=  0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[i].size();j++){
                if(dp[i][j]==-1){
                    ans = (ans+helper(dp,i,j,-1,grid,mod))%mod;
                }
                else{
                    ans = (ans+dp[i][j])%mod;
                }
            }
        }
        return ans;
    }
};