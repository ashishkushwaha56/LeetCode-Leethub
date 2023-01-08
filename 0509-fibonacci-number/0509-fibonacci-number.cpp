class Solution {
public:
    int f(int n,vector<int>&dp){
        if(n<=1) return n;
        if(dp[n]!=-1) return dp[n];
        else return dp[n]=f(n-1,dp)+f(n-2,dp);
    }
    int fib(int n) {
        vector<int> dp(n+1,-1);
        return f(n,dp);
    }
};