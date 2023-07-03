class Solution {
public:
    int mod = 1e9+7;
    // int ans = 0;
    int check(int n, int k, int target, vector<vector<int>>&dp){
        if(target == 0 and n == 0) return 1;
        if(n<=0) return 0;
        if(dp[n][target]!=-1) return dp[n][target];
        int ans = 0;
        for(int i = 1;i<=min(target,k);i++){
            ans = (ans+check(n-1,k,target-i,dp))%mod;
        }
        return dp[n][target]= ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return check(n,k,target,dp);
    }
};