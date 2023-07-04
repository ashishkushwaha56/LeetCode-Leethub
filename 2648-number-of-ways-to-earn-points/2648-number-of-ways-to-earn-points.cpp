class Solution {
public:
    int mod = 1e9+7;
    int helper(vector<vector<vector<int>>>&dp,vector<vector<int>>&types,int t,int i,int j){
        if(t <0 or i==types.size() or j > types[i][0]){
            return 0;
        }
        if(t == 0){
            return 1;
        }
        if(dp[t][i][j]!=-1) return dp[t][i][j];
        int ans = 0;
        ans = (ans+helper(dp,types,t-types[i][1],i,j+1))%mod;
        ans = (ans+helper(dp,types,t,i+1,0))%mod;
        return dp[t][i][j] = ans;
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        vector<vector<vector<int>>>dp(1001,vector<vector<int>>(51,vector<int>(51,-1)));
        return helper(dp,types,target,0,0);
    }
};