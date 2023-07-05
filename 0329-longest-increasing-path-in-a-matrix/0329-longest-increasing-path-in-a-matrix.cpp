class Solution {
public:
    vector<int>dx={0,0,-1,1};
    vector<int>dy = {1,-1,0,0};
    int dfs(vector<vector<int>>&dp,vector<vector<int>>&matrix,int i,int j,int prev){
        if(i<0 or i==matrix.size() or j<0 or j==matrix[0].size() or matrix[i][j]<=prev){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        for(int k = 0;k<4;k++){
            ans = max(ans,dfs(dp,matrix,i+dx[k],j+dy[k],matrix[i][j]));
        }
        return dp[i][j] = (ans+1);
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        int ans = 0;
        for(int i = 0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                ans = max(ans,dfs(dp,matrix,i,j,-1));
            }
        }
        return ans;
    }
};