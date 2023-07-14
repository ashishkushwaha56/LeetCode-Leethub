class Solution {
public:
    int helper(vector<vector<vector<int>>>&dp,int i,int j,vector<vector<char>>&grid,int open,int close){
        if(i == grid.size()-1 and j == grid[0].size()-1 and open == close) return dp[i][j][open-close] = 1;
        if(i == grid.size()-1 and j == grid[0].size()-1 and open !=close) return dp[i][j][open-close] = 0;
        if(dp[i][j][open-close]!=-1) return dp[i][j][open-close];
        int ans = 0;
        if(i+1<grid.size()){
            if(grid[i+1][j] == ')' and close+1<=open){
                ans = ans|helper(dp,i+1,j,grid,open,close+1);
            }
            if(grid[i+1][j] == '('){
                ans = ans|helper(dp,i+1,j,grid,open+1,close);
            }
        }
        if(j+1<grid[0].size()){
            if(grid[i][j+1]==')' and close+1<=open){
                ans = ans|helper(dp,i,j+1,grid,open,close+1);
            }
            if(grid[i][j+1]=='('){
                ans = ans|helper(dp,i,j+1,grid,open+1,close);
            }
        } 
        return dp[i][j][open-close] = ans;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(205,-1)));
        if(grid[0][0] == ')') return false;
        int a = helper(dp,0,0,grid,1,0);
        return a;
    }
};
