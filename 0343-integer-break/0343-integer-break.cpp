class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,-1);
        function<int(int,int)> helper = [&](int n,int k)->int{
            if(n == 0) {
                if(k<2) return 0;
                else{
                    return 1;
                }
            }
            if(dp[n]!=-1) return dp[n];
            int ans = 0;
            for(int i = 1;i<=n;i++){
                ans= max(ans,i*helper(n-i,k+1));
            }
            return dp[n] = ans;
        };
        return helper(n,0);
    }
};