class Solution {
public:
    int helper(vector<int>&dp,int n){
        if(n == 0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        if(dp[n]!=-1) return dp[n];
        int ans = 0;
        for(int i = 1;i<=n;i++){
            ans = max(ans,i*helper(dp,n-i));
        }
        return dp[n] = ans;
    }
    int integerBreak(int n) {
        if(n == 2) return 1;
        else if(n == 3) return 2;
        vector<int> dp(n+1,-1);
        return helper(dp,n);
    }
};