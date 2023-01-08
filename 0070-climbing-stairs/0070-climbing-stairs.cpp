class Solution {
public:
    int dp[47];
    int f(int n){
        if(n == 0) return 1;
        if(n == 1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = f(n-1)+f(n-2);
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        // for(int i = 0;i<n+1;i++){
        //     cout<<dp[i]<<" ";
        // }
        cout<<endl;
        return f(n);
    }
};