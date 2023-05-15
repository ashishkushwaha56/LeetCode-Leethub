class Solution {
public:
    // vector<int> dx = {-1,0,1};
    // vector<int> dy = {1,1,1};
    int ans = 0;
    int dfs(vector<vector<int>>&v,vector<vector<int>>&dp,int i,int j,int prev){
        if(i<0 or i>=v.size() or j<0 or j>=v[0].size()){
            return 0;
        }
        if(dp[i][j]!=0){
            return dp[i][j];
        }
        if(v[i][j]<=prev){
            return 0;
        }
        int ans = 0;
        ans = max(ans,dfs(v,dp,i-1,j+1,v[i][j]));
        ans=max(ans,dfs(v,dp,i,j+1,v[i][j]));
        ans = max(ans,dfs(v,dp,i+1,j+1,v[i][j]));
        dp[i][j] = 1+ans;
        return 1+ans;
    }
    int maxMoves(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size()));
        int ans = 0;
        for(int i = 0;i<grid.size();i++){
            int a = dfs(grid,dp,i,0,-1);
            if(dp[i][0]>1) ans= max(ans,dp[i][0]-1);
        }
        return ans;
    }
};