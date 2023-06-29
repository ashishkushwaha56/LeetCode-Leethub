class Solution {
public:
int solve(int m, int n, vector<vector<int>> &triangle, int &t, vector<vector<int>> &dp){
    if(m == t){
        return triangle[m][n];
    }

    if(dp[m][n] != -1){
        return dp[m][n];
    }

    int down = triangle[m][n] + solve(m+1, n, triangle, t, dp);
    int diagonal = triangle[m][n] + solve(m+1, n+1, triangle, t, dp);

    return dp[m][n]=min(down, diagonal);
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int t = triangle.size()-1;
        vector<vector<int>> dp(triangle.size(),vector<int>(triangle[triangle.size()-1].size(),-1));
        
        return solve(0, 0, triangle, t, dp);
        
    }
};